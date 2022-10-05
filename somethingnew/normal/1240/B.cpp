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
#define all(x) (x).begin(), (x).end()

using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, pair<int, int>> mp;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (mp[a[i]].first == 0)
            mp[a[i]].first = i + 1;
        mp[a[i]].second = i;
    }
    vector<pair<int, pair<int, int>>> b;
    for (auto [key, val] : mp) {
        val.first--;
        b.push_back({key, val});
    }
    sort(all(b));
    vector<int> dp(b.size());
    dp[0] = 1;
    int mx = 1;
    for (int i = 1; i < b.size(); ++i) {
        if (b[i].second.first > b[i-1].second.second)
            dp[i] = dp[i - 1] + 1;
        else
            dp[i] = 1;
        mx = max(mx, dp[i]);
    }
    cout << b.size() - mx << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}