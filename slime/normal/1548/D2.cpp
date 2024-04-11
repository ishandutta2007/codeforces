//
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 6005;
ll cal(vector<pi> c) {
    int n = c.size();
    int cnt[4] = {0, 0, 0, 0};
    for (auto v : c) 
        cnt[2 * (v.fi % 2) + (v.se % 2)] += 1;
    ll ans = 1ll * n * (n - 1) * (n - 2) / 6;
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            for (int k = j + 1; k < 4; k++)
                ans -= 1ll * cnt[i] * cnt[j] * cnt[k];
    return ans;
}
int x[maxn], y[maxn];
int d[maxn][maxn];
vi r[4][4];
int h[4][4][4];
int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &x[i], &y[i]),
        r[x[i] % 4][y[i] % 4].pb(i);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            d[i][j] = d[j][i] = gcd(abs(x[i] - x[j]), abs(y[j] - y[i]));
    ll ans = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            vector<pi> f;
            for (int k = 1; k <= n; k++)
                if ((x[k] % 2 == i) && (y[k] % 2 == j)) f.pb(mp(x[k] / 2, y[k] / 2));
            ans += cal(f);
        }
    for (int i = 1; i <= n; i++) {
        memset(h, 0, sizeof(h));
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                for (auto v : r[j][k])
                    h[j][k][d[i][v] % 4] += 1;

        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                for (int l = 0; l < 4; l++)
                    for (int s = 0; s < 4; s++) {
                        if ((l - j) % 2) continue;
                        if ((s - k) % 2) continue;
                        if (mp(l, s) < mp(j, k)) continue;

                        if ((j - x[i]) % 2 == 0 && (k - y[i]) % 2 == 0) continue;
                        for (int u = 0; u < 4; u++)
                            for (int v = 0; v < 4; v++) {
                                int ar = (l - j) * (y[i] - k) - (x[i] - j) * (s - k);
                                ar %= 4;
                                if (ar < 0) ar += 4;

                                if (mp(l, s) == mp(j, k)) ar += 4;
                                else ar += 2;
                                
                                if ((ar + u + v) % 4) continue;
                                if (mp(l, s) == mp(j, k)) {
                                    if (u < v) continue;
                                    if (u > v) ans += 1ll * h[j][k][u] * h[j][k][v];
                                    else ans += 1ll * h[j][k][u] * (h[j][k][u] - 1) / 2;
                                }
                                else {
                                    ans += 1ll * h[j][k][u] * h[l][s][v];
                                }
                            }
                    }
    }
    cout << ans << endl;
    return (0-0); //<3
}