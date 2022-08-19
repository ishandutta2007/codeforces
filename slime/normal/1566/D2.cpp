//Awwawa! Dis cold yis ratten buy Pikachu!
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
const int maxn = 305;
int a[maxn * maxn];
int s[maxn][maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pi> cr;
        int ids = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                ids += 1;
                scanf("%d", &a[ids]);
                cr.pb(mp(a[ids], -ids));
            }
        sort(cr.begin(), cr.end());
        int ni = 1, nj = 1;
        int p = 0;
        while (p < cr.size()) {
            int q = p;
            while (q < cr.size() && cr[q].fi == cr[p].fi ) q += 1;
            vi cur;
            for (int j = p; j < q; j++) cur.pb(-cr[j].se);
            while (cur.size()) {
                int tr = m - nj + 1;
                tr = (int)cur.size() - tr;
                chkmax(tr, 0);
                for (int u = tr; u < cur.size(); u++) {
                    s[ni][nj] = cur[u];
                    nj += 1;
                    if (nj > m) nj = 1, ni += 1;
                }
                cur.resize(tr);
            }
            p = q;
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)  {
            for (int j = 1; j <= m; j++) {
                for (int k = 1; k < j; k++)
                    if (s[i][k] < s[i][j]) ans += 1;
            }
        }
        printf("%lld\n", ans);
    }
    return (0-0); //<3
}
/*
1

2 9
1 3 3 3 3 3 1 1 3 1 3 1 1 3 3 1 1 3
*/