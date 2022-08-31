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
int n, m;
int mpp[maxn];
int hv[maxn];
char inp[maxn];
vi eg[maxn];
int nd[maxn];
bool chk(int a, int b) {
    return a >= 1 && a <= n && b >= 1 && b <= m;
}
int id(int u, int v) {
    return (u - 1) * m + v;
}
int st[maxn], top = 0;
int dfn[maxn], low[maxn], dfcnt, bl[maxn], inq[maxn];

int col[maxn]; // color of node

int sccnt = 0;
vi tot[maxn]; 
int bccol[maxn]; // col of bc

int fr[maxn];
void dfs(int u) {
    dfn[u] = low[u] = ++dfcnt;
    st[top++] = u, inq[u] = 1;
    for (auto v : eg[u]) {
        if (!dfn[v]) {
            dfs(v);
            chkmin(low[u], low[v]);
        }
        else {
            if (inq[v]) chkmin(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        sccnt++;
        while (1) {
            int h = st[top - 1]; top--;
            inq[h] = 0, tot[sccnt].pb(h);
            bl[h] = sccnt;
            //cout << "BL" << h << ' ' << sccnt << endl;
            if (col[h]) bccol[sccnt] = 1;
            for (auto v : eg[h]) {
                bccol[sccnt] |= bccol[bl[v]];
                if (bl[v] != sccnt) fr[bl[v]] = 1;
            }
            if (h == u) break;
        }
    }
}
int bg[maxn];
int a[maxn];
int main() {
    cin >> n >> m;
    int idcnt = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%s", inp + 1);
        for (int j = 1; j <= m; j++)
            if (inp[j] == '#') mpp[id(i, j)] = 1, nd[id(i, j)] = ++idcnt;
    }
    vector<pi> cr;
    for (int j = 1; j <= m; j++) {
        scanf("%d", &a[j]);
        vi ls;
        bg[j] = n + 1;
        for (int i = n; i >= 1; i--)
            if (mpp[id(i, j)]) ls.pb(i);
        //cout << "!!!" << j << ' ' << ls.size() << ' ' << a[j] << endl;
        if (!ls.size()) continue;
        col[nd[id(ls[a[j] - 1], j)]] = 1;
        
        for (int i = 0; i < ls.size(); i++) {
            int nx = n + 1;
            if (i != 0) nx = ls[i - 1];
            int nid = nd[id(ls[i], j)];
            for (int k = ls[i]; k < nx; k++) {
                if (chk(k, j - 1) && nd[id(k, j - 1)])
                    eg[nid].pb(nd[id(k, j - 1)]);
                if (chk(k, j + 1) && nd[id(k, j + 1)])
                    eg[nid].pb(nd[id(k, j + 1)]);
            }
            if (i) eg[nid].pb(nd[id(ls[i - 1], j)]);
            if (i != ls.size() - 1 && ls[i + 1] - ls[i] == -1)
                eg[nid].pb(nd[id(ls[i + 1], j)]);
        }
    }
    //cout << "ADE" << endl;
    int ans = 0;
    for (int i = 1; i <= idcnt; i++)
        if (!dfn[i]) dfs(i);
    for (int i = 1; i <= sccnt; i++)
        if (!fr[i]) ans++;//, cout << "!!!" << i << endl;
    cout << ans << endl;
    return 0;
}