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
const int maxn = 300005;
map<pi, int> bad;
int a[maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vi cur;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), cur.pb(a[i]);
        sort(cur.begin(), cur.end());
        vector<pi> s;
        for (int i = 0; i < cur.size(); ) {
            int j = i;
            while (j < cur.size() && cur[j] == cur[i]) j++;
            s.pb(mp(j - i, cur[i]));
            i = j;
        }
        sort(s.begin(), s.end());
        vi pls;
        bad.clear();
        while (m--) {
            int u, v;
            scanf("%d%d", &u, &v);
            bad[mp(u, v)] = bad[mp(v, u)] = 1;
        }
        for (int i = s.size() - 1; i >= 0; i--) 
            if (i == s.size() - 1 || s[i].fi != s[i + 1].fi) pls.pb(i);
        auto calc = [&](int i, int j) {
            ll ans = 0;
            ans = 1ll * (s[i].fi + s[j].fi) * (s[i].se + s[j].se);
            return ans;
        };
        ll res = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (auto v : pls) {
                int p = v;
                while (1) {
                    if (p < 0 || s[p].fi != s[v].fi) break;
                    ll cr = calc(i, p);
                    if (cr < res) break;
                    if (s[i].se == s[p].se || bad[mp(s[i].se, s[p].se)]) {
                        p--;
                        continue;
                    }
                    else {
                        chkmax(res, cr);
                        break;
                    }
                }
            }
        }
        cout << res << endl;
    }
    return (0-0); //<3
}