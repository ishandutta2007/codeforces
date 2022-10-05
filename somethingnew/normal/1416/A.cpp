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
void solve(){
    int n;
    cin >> n;
    vector<int> ans(n, -1);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        mp[a].push_back(i);
    }
    for (const auto& k : mp) {
        vector<int> lst = k.second;
        int maxdist = 0;
        lst.push_back(-1);
        lst.push_back(n);
        sort(lst.begin(), lst.end());
        for (int i = 1; i < lst.size(); ++i) {
            maxdist = max(maxdist, lst[i] - lst[i-1]);
        }
        if(ans[maxdist - 1] == -1)
            ans[maxdist - 1] = k.first;
        ans[maxdist - 1] = min(ans[maxdist - 1], k.first);
    }
    int res = -1;
    for (int j = 0; j < n; ++j) {
        if(res == -1)
            res = ans[j];
        if(ans[j] != -1)
            res = min(res, ans[j]);
        cout << res << ' ';
    }
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}