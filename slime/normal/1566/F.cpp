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
const int maxn = 200005;
ll dp[maxn];
ll ff[maxn];
const ll inf = 1e18;
int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<pi> ar;
        vi a;
        int n, m;
        scanf("%d%d", &n, &m);
        a.resize(n), ar.resize(m);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a.begin(), a.end());
        for (int i = 0; i < m; i++)
            scanf("%d%d", &ar[i].fi, &ar[i].se);
        sort(ar.begin(), ar.end());

        vector<pi> nx;
        for (auto v : ar) {
            int p = lower_bound(a.begin(), a.end(), v.fi) - a.begin();
            if (p < a.size() && a[p] <= v.se) continue;
            nx.pb(v);
        }
        int tr = mod;
        ar = nx; nx.clear();
        reverse(ar.begin(), ar.end());
        for (auto v : ar) {
            if (v.se >= tr) continue;
            nx.pb(v);
            //cout << "LE" << v.fi << ' ' << v.se << endl;
            chkmin(tr, v.se);
        }
        ar = nx;
        sort(ar.begin(), ar.end());
        nx = ar;
        if (!nx.size()) {
            printf("0\n");
            continue;
        }
        vi nid(nx.size());
        vector<vi> ee(a.size() + 1);
        for (int j = 0; j < nx.size(); j++) {
           // cout << "LE" << nx[j].fi << ' ' << nx[j].se << endl;
            int p = lower_bound(a.begin(), a.end(), nx[j].fi) - a.begin();
            nid[j] = p;
            ee[p].pb(j);
        }
        //for (auto m : a) cout << m << ' '; cout << endl;
        a.pb(mod * 2);
        for (int j = a.size() - 1; j >= 0; j--) {
            if (j == a.size() - 1) {
                for (auto s : ee[j]) dp[s] = inf;
                dp[nx.size()] = 0;
                ff[j] = 0;
                continue;
            }
            // choose not, f
            ff[j] = ff[j + 1];
            if (ee[j + 1].size()) 
                ff[j] = dp[ee[j + 1][0]];
            
            ll mn[2] = {inf, inf};
            for (auto v : ee[j + 1]) {
                ll d = nx[v].fi - a[j];
                ll nxt = dp[v + 1];
                if (v == ee[j + 1][ee[j + 1].size() - 1])
                    nxt = ff[j + 1];
                chkmin(mn[0], d + nxt);
                chkmin(mn[1], 2 * d + nxt);
                chkmin(ff[j], d + nxt);
            }
            if (ee[j].size()) {
                int lst = ee[j][ee[j].size() - 1];
                ll na = dp[lst + 1];
                if (lst + 1 == nx.size() || nx[lst + 1].fi >= a[j + 1]) 
                    na = ff[j + 1];
                chkmin(mn[0], na);
                chkmin(mn[1], na);
            }
            for (auto v : ee[j]) {
                dp[v] = inf;
                ll d = max(0, a[j] - nx[v].se);
                chkmin(dp[v], mn[1] + d);
                chkmin(dp[v], mn[0] + 2 * d);
            //    cout << "EE " << v << ' ' << dp[v] << endl;
            }
            //cout << "FF" << j << ' ' << ff[j] << endl;
        }
        ll ans = inf;
        if (nx[0].fi < a[0]) ans = dp[0];
        else ans = ff[0];
        printf("%lld\n", ans);
    }
    return (0-0); //<3
}
/*
1

4 12
-9 -16 12 3
-20 -18
-14 -13
-10 -7
-3 -1
0 4
6 11
7 9
8 10
13 15
14 18
16 17
18 19*/