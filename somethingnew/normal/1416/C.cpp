#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define int long long
using namespace std;
vector<pair<int,int>> solve(const vector<vector<bool>> &nums, int bit){
    if(nums.size() == 0)
        return vector<pair<int,int>>(32, {0, 0});
    vector<vector<bool>> next1;
    vector<vector<bool>> next0;
    int res = 0;
    int invres = 0;
    int zn = 0;
    int invzn = 0;
    for (const auto & num : nums) {
        if(num[bit]){
            zn++;
            next1.push_back(num);
            invres += invzn;
        }else{
            invzn++;
            next0.push_back(num);
            res += zn;
        }
    }
    vector<pair<int,int>> ans(32, {0, 0});
    ans[bit] = {invres, res};
    if(bit > 0) {
        vector<pair<int, int>> ans0 = solve(next0, bit - 1);
        vector<pair<int, int>> ans1 = solve(next1, bit - 1);
        for (int i = 0; i < bit; ++i) {
            ans[i].first = ans0[i].first + ans1[i].first;
            ans[i].second = ans0[i].second + ans1[i].second;
        }
    }
    return ans;
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<bool>> lst(n, vector<bool>(32, 0));
    vector<int> type(n, 0);
    vector<int> typezn(1, 0);
    for (auto &i : lst) {
        int a;
        cin >> a;
        int ind = 0;
        while(a){
            i[ind] = a % 2;
            a /= 2;
            ind++;
        }
    }
    int x = 0;
    int ans = 0;
    vector<pair<int,int>> res = solve(lst, 31);
    for (int i = 0; i < res.size(); ++i) {
        if(res[i].first < res[i].second)
            x += (1 << i);
        //cerr << res[i].first << ' ' << res[i].second << endl;
        ans += min(res[i].first, res[i].second);
    }
    cout << ans << ' ' << x;
}