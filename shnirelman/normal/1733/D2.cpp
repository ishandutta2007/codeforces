#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 998244353;
const int N = 2e5 + 13;

/*
1
6 2 11
000001
100000
*/

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    string a, b;
    cin >> a >> b;

    vector<int> pos;
    for(int i = 0; i < n; i++)
        if(a[i] != b[i])
            pos.push_back(i);

    if(pos.size() % 2 != 0) {
        cout << -1 << endl;
        return;
    }

    if(pos.empty()) {
        cout << 0 << endl;
        return;
    }

    if(x >= y) {
        li ans = 0;
        for(int i = 0; i < pos.size() / 2; i++) {
            ans += (pos[i] + 1 == pos[i + pos.size() / 2] ? min(x, y * 2) : y);
        }

        cout << ans << endl;
    } else {
        vector<pii> c(1, pii(pos[0], 1));
        for(int i = 1; i < pos.size(); i++) {
            if(pos[i] - pos[i - 1] == 1)
                c.back().s++;
            else
                c.emplace_back(pos[i], 1);
        }

//        for(auto p : c)
//            cout << "c : " << p.f << ' ' << p.s << endl;

        int m = c.size();
        vector<li> dp(m + 1, INF64);
        dp[0] = 0;
        int cur = 0;
        for(int i = 0; i < m; i++) {
            cur += c[i].s;

            if(c[i].s % 2 == 1) {
                if(cur % 2 == 0) {
                    dp[i + 1] = dp[i] + c[i].s / 2 * 1ll * x + y;
                } else {
                    dp[i + 1] = dp[i] + c[i].s / 2 * 1ll * x;
                }

                int cur2 = 0;
                for(int j = 0; j < i; j++) {

                    if(cur2 % 2 == cur % 2) {
                        int c1 = cur - cur2;
                        int c0 = c[i].f + c[i].s - c[j].f - c1;
                        dp[i + 1] = min(dp[i + 1], dp[j] + (c0 + c1 / 2) * 1ll * x);
                    }
                    cur2 += c[j].s;
                }
            } else {
                dp[i + 1] = dp[i] + c[i].s / 2 * 1ll * x;
            }
        }

        cout << dp[m] << endl;
//        vector<vector<vector<li>>> dp(m + 1, vector<vector<li>>(2, vector<li>(2, INF64)));
//        dp[0][0][0] = 0;
//
//        int lst = -1;
//        int cnt = 0;
//        for(int i = 0; i < m; i++) {
//            if(c[i].s % 2 == 0) {
//                cnt += c[i].s;
//
//
//            } else {
//
//            }
//        }

//        vector<li> dp(c.size() + 1, INF64);
//        dp[0] = 0;
//        int cur = 0;
//        for(int i = 0; i < c.size(); i++) {
//            if(c[i].s % 2 == 0 && cur % 2 == 0)
//                dp[i + 1] = dp[i] + c[i].s / 2 * 1ll * x;
//            else if(c[i].s % 2 != 0 && cur % 2 != 0) {
//                int cur2 = 0;
//                for(int j = 0; j < i; j++) {
//                    if(cur % 2 )
//                }
//            }
//        }
    }


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}