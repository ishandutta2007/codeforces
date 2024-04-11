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
const int maxn = 400005;
int fa[maxn];
int gfa(int a) {
    if (fa[a] == a) return a;
    return fa[a] = gfa(fa[a]);
}
int n, m;
int u[maxn], v[maxn], c[maxn];
void clr() {
    for (int i = 1; i <= n; i++) fa[i] = i;
}
set<int> cur;
struct eg {
    int u, v, w;
    bool operator < (const eg &h) const {
        return w < h.w;
    }
}p[2000005];
unordered_map<int, int> hv[maxn];
void dfs(int a) {   
    int fr = 0;
    while (1) {
        auto nx = cur.lower_bound(fr);
        if (nx == cur.end()) return ;
        fr = (*nx) + 1;
        if (hv[a][*nx]) continue;
        else {
            int res = *nx;
            fa[res] = fa[a];
            cur.erase(res);
            dfs(res);
        }
    }
}
int use[2000005];
int main() {
    cin >> n >> m;
    int x = 0;
    for (int i = 1; i <= m; i++) scanf("%d%d%d", &u[i], &v[i], &c[i]), hv[u[i]][v[i]] = hv[v[i]][u[i]] = 1;
    if (n > 1000) {
        clr();
        for (int i = 1; i <= n; i++)
            cur.insert(i);
        while (!cur.empty()) {
            int h = (*cur.begin()); cur.erase(h); dfs(h);
        }
        for (int i = 1; i <= m; i++)
            p[i].u = u[i], p[i].v = v[i], p[i].w = c[i];
        sort(p + 1, p + m + 1);
        ll ans = 0;
        for (int i = 1; i <= m; i++) {
            if (gfa(p[i].u) == gfa(p[i].v)) continue;
            fa[gfa(p[i].u)] = gfa(p[i].v);
            ans += p[i].w;
        }
        cout << ans << endl;
    }
    else {
        int x = 0;
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            x ^= c[i];
            p[cnt].u = u[i], p[cnt].v = v[i], p[cnt].w = c[i];
            cnt++;
        }
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                if (!hv[i][j]) {
                    p[cnt].u = i, p[cnt].v = j, p[cnt++].w = 0;
                }
        sort(p, p + cnt);
        clr();
        ll ans = 0;
        for (int i = 0; i < cnt; i++) {
            if (gfa(p[i].u) == gfa(p[i].v)) continue;
            fa[gfa(p[i].u)] = gfa(p[i].v);
            use[i] = 1;
            ans += p[i].w;
        }
        int inc = x;
        for (int i = 0; i < cnt; i++) 
            if (!use[i] && p[i].w == 0) inc = 0;
        clr();
        for (int i = 0; i < cnt; i++) 
            if (p[i].w && use[i])
                fa[gfa(p[i].u)] = gfa(p[i].v);
        for (int i = 0; i < cnt; i++)
            if (p[i].w && gfa(p[i].u) != gfa(p[i].v))
                chkmin(inc, p[i].w);
        ans += inc;
        cout << ans << endl;
    }
    return 0;
}