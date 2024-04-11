//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 14;
int d[maxn][maxn];
int a[maxn];
int f[1 << maxn];
int to[1 << maxn][maxn];
int n;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i][j] = 1ll * a[i] * ksm((a[i] + a[j]) % mod, mod - 2) % mod;
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++) {
            to[i][j] = 1;
            for (int k = 0; k < n; k++)
                if (i & (1 << k))
                    to[i][j] = 1ll * to[i][j] * d[j][k] % mod;
        }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        memset(f, 0, sizeof(f));
        f[1 << i] = 1;
        for (int j = 0; j < (1 << n); j++) {
            if (!(j & (1 << i))) continue;
            if (j == (1 << i)) continue;
            f[j] = 1;
            for (int u = j; u; u = (u - 1) & j) {
                if (!(u & (1 << i))) continue;
                if (u == j) continue;
                ll cur = f[u];
                for (int s = 0; s < n; s++) {
                    if ((u ^ j) & (1 << s))
                        cur = cur * to[u][s] % mod;
                }
                f[j] = (f[j] - cur) % mod;
            }
        }
        ans += f[(1 << n) - 1];
        ans %= mod;
    }
    if (ans < 0) ans += mod;
    cout << ans << endl;
    return (0-0); //<3
}