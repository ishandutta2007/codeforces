/*
    Soheil Mohammadkhani
    Div3. Contest :|
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define debug2(x)                   cerr << #x << ": " <<  x <<  " ";
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 100 + 3;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, g[MAXN][MAXN], dp[MAXN][MAXN];

ll fixed_dp(ll base) {
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = INF;
            if (i == 0 && j == 0) {
                dp[0][0] = g[0][0] - base;
                if (dp[0][0] < 0) return INF;
            }
            ll h = (base + i + j);
            ll diff = g[i][j] - h;
            if (diff >= 0) {
                if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + diff);
                if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + diff);
            }
        }
    }

//    debug(dp[0][1]);

    return dp[n - 1][m - 1];
}

ll solve() {
    cin >> n >> m;
    queue<ll> base_q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            base_q.push(g[i][j] - i - j);
        }
    }

//    debug(fixed_dp(1));

    ll bf = INF;
    while (!base_q.empty()) {
        bf = min(bf, fixed_dp(base_q.front()));
        base_q.pop();
    }

    cout << bf << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}