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
const int maxn = 300005;
vi eg[maxn];
int mn[maxn];
int dfn[maxn];
int nd[maxn]; // should end up with what
int a[maxn];
int pl[maxn];
int dep[maxn], fa[maxn];
int n;

void dfs1(int x) {
    mn[x] = a[x];
    for (auto v : eg[x]) {
        dfs1(v);
        chkmin(mn[x], mn[v]);
    }
    vector<pi> cur;
    for (auto v : eg[x]) {
        cur.pb(mp(mn[v], v));
    }
    sort(cur.begin(), cur.end());
    eg[x].clear();
    for (auto v : cur)
        eg[x].pb(v.se);
}
int dfcnt = 0, ndcnt = 0;
void dfs2(int a) {
    dfn[a] = ++dfcnt;
    for (auto v : eg[a]) {
        fa[v] = a, dep[v] = dep[a] + 1;
        dfs2(v);
    }
    nd[a] = ++ndcnt;
}
void otpok(ll res) {
    cout << "YES" << endl;
    cout << res << endl;
    for (int i = 1; i <= n; i++)
        printf("%d ", dfn[i]);
}
bool fr[maxn];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        pl[a[i]] = i;
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        eg[u].pb(v);
    }
    dfs1(1);
    dfs2(1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) { 
        if (nd[pl[i]] == i) {
            ans += dep[pl[i]];
            continue;
        }
        else {
            ans += dep[pl[i]];
            bool chk = 1;

            for (int j = 1; j <= n; j++)
                if (nd[j] <= i) fr[dfn[j]] = 1;
            
            int shd = 0;
            for (int j = 1; j <= n; j++)
                if (nd[j] == i) shd = j;
            vi f, t;

            int v = shd;

            while (v) {
                if (v != pl[i])
                    f.pb(a[v]);
                fr[dfn[v]] = 1;
                v = fa[v];
            }
            for (int j = 1; j <= i; j++)
                fr[j] = 0;

            for (int s = i + 1; s <= n; s++)
                if (!fr[s] && dfn[pl[s]] != s) 
                    chk = 0;
                
            for (int s = 1; s <= n; s++)
                if (fr[s]) t.pb(s);

            reverse(f.begin(), f.end());
            if (f.size() != t.size()) chk = 0;
            for (int j = 0; j < f.size(); j++)
                if (f[j] != t[j]) chk = 0;
            if (!chk) 
                cout << "NO" << endl;
            else otpok(ans);
            return 0;
        }
    }
    otpok(ans);
    return 0;
}