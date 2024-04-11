#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <ctime>
#include <set>
#include <map>
         
using namespace std;
         
typedef long long ll;
typedef long double ld;
const ll MSIZE = 200000;
const ll INF = 1e18;
const ld EPS = 1e-9;
const int alp = 26;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    vector<int> dp(v.size() + 1);
    for (int i = 0; i < n; ++i){
        if (v[i] == 0){
            int l = max(0, i - k), r = min(i + k, n - 1);
            dp[i] = r - l + 1;
        } else {
            int l = max(v[i] + k, i - k), r = min(i + k, n - 1);
            dp[i] = dp[v[i] - 1];
            if (r >= l)
                dp[i] += (r - l + 1);
        }
    }
    for (int i = 0; i < n; ++i)
        cout << dp[i] << ' ';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    //freopen("scrivener.in", "r", stdin);
    //freopen("scrivener.out", "w", stdout);
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    solve();
    //cerr << '\n' << fixed << setprecision(6) << ld(clock()) / CLOCKS_PER_SEC;
    return 0;
}