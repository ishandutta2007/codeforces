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

using namespace std;
inline bool f(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
    return b.first - a.first >= abs(a.second.first - b.second.first) + abs(a.second.second - b.second.second);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, r;
    cin >> r >> n;
    n++;
    vector<pair<int, pair<int,int>>> lst(n,{0,{0,0}});
    lst[0].first = -1;
    for (auto & i : lst) {
        if(i.first == -1)
            i = {0, {1, 1}};
        else
            cin >> i.first >> i.second.first >> i.second.second;
    }
    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; --i) {
        for (int tpl = 1; tpl < 2002; ++tpl) {
            if(i + tpl == n)
                break;
            if(f(lst[i], lst[i + tpl]))
                ans[i] = max(ans[i], ans[i + tpl] + 1);
        }
    }
    cout << ans[0];
}