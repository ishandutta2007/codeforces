#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 1e6 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

/*
*/

int a[N][3];

int dp[N][8];

int n, m;

int price(int i, int mask) {
    int res = 0;
    for(int j = 0; j < m; j++) {
        res += ((mask >> j) & 1) ^ a[i][j];
    }

    return res;
}

bool can(int mask, int nmask) {
    for(int i = 0; i + 1 < m; i++) {
        int cnt = ((mask >> i) & 1) + ((mask >> i + 1) & 1) + ((nmask >> i) & 1) + ((nmask >> i + 1) & 1);
        if(cnt % 2 == 0)
            return false;
    }

    return true;
}

void solve() {

    cin >> n >> m;

    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    if(n >= 4 && m >= 4) {
        cout << -1 << endl;
        return;
    }

    if(n < m) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                a[j][i] = (s[i][j] - '0');
            }
        }

        swap(n, m);
    } else {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                a[i][j] = (s[i][j] - '0');
            }
        }
    }

    if(m == 1) {
        cout << 0 << endl;
        return;
    }
//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < m; j++) {
//            cout << a[i][j] << ' ';
//        }
//        cout << endl;
//    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < (1 << m); j++) {
            dp[i][j] = INF;
        }
    }

    for(int mask = 0; mask < (1 << m); mask++) {
        dp[0][mask] = price(0, mask);
    }

    for(int i = 0; i < n - 1; i++) {
        for(int mask = 0; mask < (1 << m); mask++) if(dp[i][mask] < INF) {
            for(int nmask = 0; nmask < (1 << m); nmask++) if(can(mask, nmask)) {
                dp[i + 1][nmask] = min(dp[i + 1][nmask], dp[i][mask] + price(i + 1, nmask));
            }
        }
    }

    int ans = INF;
    for(int i = 0; i < (1 << m); i++) {
        ans = min(ans, dp[n - 1][i]);
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}