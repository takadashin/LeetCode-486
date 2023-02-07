#include <iostream>
#include <vector>
#include <set>
#include <Queue>
#include <map>
#include <stack>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <sstream>
#include <unordered_set>
#include <bitset>
#include <functional>
#include <numeric>


bool canWindfs(vector<int>& nums,int i,int j, int scoreself, int scoreopp, int& total)
{
    if (i == j)
        return scoreself + nums[i] >= scoreopp;

    bool res = (canWindfs(nums, i + 1, j, scoreopp, scoreself + nums[i], total));
    res = res && canWindfs(nums, i, j - 1, scoreopp, scoreself + nums[j], total);
    return  !res;
            

}

bool PredictTheWinner(vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (nums.size() < 2)
        return true;
    return canWindfs(nums,0, nums.size()-1, 0, 0, total);
}
