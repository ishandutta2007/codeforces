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
const int maxn = 100005;
int n;
int x[maxn];
vector<pi> cur;
int cnt = 0;
pi g[maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            scanf("%d", &x[i]);
        cur.clear();
        ll ans = 0;
        for (int i = n; i >= 1; i--) {
            cnt = 0;
            cur.pb(mp(x[i], 1));
            for (auto v : cur) {
                int a = v.fi, t = v.se;
                int nd = (x[i] + a - 1) / a;
                int e = (x[i] / nd);
                ll nans = 1ll * t * (nd - 1) % mod * i % mod;
                ans = (ans + nans) % mod;
                g[cnt++] = mp(e, t);            
            }
            sort(g, g + cnt);
            int nc = 0;
            cur.clear();
            for (int i = 0; i < cnt; ) {
                int j = i;
                int s = 0;
                while (j < cnt && g[j].fi == g[i].fi) 
                    s += g[j].se, j += 1;
                cur.pb(mp(g[i].fi, s));
                i = j;
            } 
        }
        ans %= mod;
        if (ans < 0) ans += mod;
        cout << ans << endl;
    }
    return (0-0); //<3
}