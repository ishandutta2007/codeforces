#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pld = pair<ld, ld>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 1013;
const int LOGN = 10;
const int K = 22;
const int M = 1e9 + 7;
const int A = 26;

/*
*/

void solve() {
    int n;
    cin >> n;

    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        mp[x].push_back(i);
    }

    int ans = 0;
    for(auto p : mp) {
        if(p.s.size() >= 2) {
            for(int i = 0; i < p.s.size() - 1; i++) {
                ans = max(ans, p.s[i] + n - p.s[i + 1]);
            }
//            ans = max(ans, p.s[0] + n - p.s[1]);
        }
    }

    cout << (ans == 0 ? -1 : ans) << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}