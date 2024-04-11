/*
    Soheil Mohammadkhani
    IDK :)
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
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 102;
const ll LOG = 22;
const ll INF = 8e18;
const ll NMAX = 2e17;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN][MAXN][MAXN][2] = {0};
ll a[MAXN] = {0};

void prep() {
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            for (int k = 0; k < MAXN; k++) {
                dp[i][j][k][0] = INF;
                dp[i][j][k][1] = INF;
            }
        }
    }
}

int main() {
    fast_io;
    prep();
    dp[0][0][0][0] = dp[0][0][0][1] = 0;
    ll n;
    cin >> n;
    ll e = 0, o = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        if (a[i] % 2 == 0) { if (a[i] != 0) e++; }
        else o++;
    }

    e = floor(n / 2.0) - e;
    o = ceil(n / 2.0) - o;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n; k++) {
                if (k + j != i) continue;
                if (a[i] == 0) {
                    if (k > 0) dp[i][j][k][0] = min(dp[i - 1][j][k - 1][1] + 1, dp[i - 1][j][k - 1][0]);
                    if (j > 0) dp[i][j][k][1] = min(dp[i - 1][j - 1][k][0] + 1, dp[i - 1][j - 1][k][1]);
                } else if (a[i] % 2 == 0) {
                    if (k > 0) dp[i][j][k][0] = min(dp[i - 1][j][k - 1][1] + 1, dp[i - 1][j][k - 1][0]);
                } else if (a[i] % 2 == 1) {
                    if (j > 0) dp[i][j][k][1] = min(dp[i - 1][j - 1][k][0] + 1, dp[i - 1][j - 1][k][1]);
//                    cout << i - 1 << sep << j - 1 << sep << k << sep << 0 << sep << dp[i - 1][j - 1][k][0] + 1 << endl;
                }
            }
        }
    }

//    cout << o << " " << e << endl;
//    cout << dp[6][3][3][1] << endl;
    cout << min(dp[n][ll(ceil(n / 2.0))][n / 2][0], dp[n][ll(ceil(n / 2.0))][n / 2][1]) << endl;

    return 0;
}