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
struct th {
    int u, v;
    int w;
    th() {}
    th(int a, int b, int c) {
        u = a, v = b, w = c;
    }
}p[maxn];

int n, k;
int cnt = 0;
int fa[maxn];
int gfa(int a) {
    if (fa[a] == a) return a;
    return fa[a] = gfa(fa[a]);
}
void ini() {
    for (int i = 1; i <= n; i++) fa[i] = i;
}
void lk(int a, int b) {
    fa[gfa(a)] = gfa(b);
}
vector<pi> eg[maxn];
int dis[maxn];
int S, T;
int pre[maxn];
const int N = 55;
int fl[maxn];
int d[N], cd[N];

int w[N][N];

vector<pi> preg;
int nans = 0;
const int inf = 50000;

void ade(int u, int v, int w) {
    eg[u].pb(mp(v, w));
}
int q[maxn * maxn], fr, ed;
int inq[maxn];
bool bfs() {
    S = cnt + 1, T = cnt + 2;
    for (int i = 1; i <= T; i++) eg[i].clear();
    //  
    //  
    vi fls;
    for (int i = 1; i <= cnt; i++) {
        if (fl[i]) fls.pb(i);
    }
    for (int i = 0; i <= cnt; i++) {
        if (i != 0 && !fl[i]) continue;
        ini();
        for (auto v : preg)
            lk(v.fi, v.se);
        for (auto j : fls) {
            if (j == i) continue;
            lk(p[j].u, p[j].v);
        }
        int nid = i;
        if (i == 0) nid = S;
        for (int i = 1; i <= cnt; i++) {
            if (fl[i]) continue;
            if (gfa(p[i].u) != gfa(p[i].v))     
                ade(nid, i, inf - p[i].w);
        }
    }
    for (int i = 0; i <= cnt; i++) {
        if (i != 0 && !fl[i]) continue;
        memset(cd, 0, sizeof(cd));
        for (auto v : preg)
            cd[v.fi] += 1, cd[v.se] += 1;
        for (auto j : fls) {
            if (j == i) continue;
            cd[p[j].u] += 1, cd[p[j].v] += 1;
        }
        int nid = i;
        if (i == 0) nid = T;
        int nw = inf - p[nid].w;
        if (nid == T) nw = 0;
        for (int i = 1; i <= cnt; i++) {
            if (fl[i]) continue;
            if (cd[p[i].u] < d[p[i].u] && cd[p[i].v] < d[p[i].v]) 
                ade(i, nid, -nw);
        }
    }
    for (int i = 1; i <= T; i++) dis[i] = -inf, inq[i] = 0;
    int fr = 0, ed = 0;
    dis[S] = 0; q[ed++] = S, inq[S] = 1;
    while (fr < ed) {
        int cur = q[fr++]; inq[cur] = 0;
        for (auto v : eg[cur]) {
            int eid = v.fi, ew = v.se;
            if (chkmax(dis[eid], dis[cur] + ew)) {
                pre[eid] = cur;
                if (!inq[eid]) q[ed++] = eid, inq[eid] = 1;
            }
        }
    }
    if (dis[T] <= 0) return 0;
    vi cc;
    int ee = pre[T];
    while (1) {
        cc.pb(ee);
        ee = pre[ee];
        if (ee == S) break;
    }
    nans += dis[T];
    //cout << "INC" << dis[T] << endl;
    for (auto v : cc)
        fl[v] ^= 1;
    return 1;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
        cin >> d[i];
    for (int i = k + 1; i <= n; i++)
        d[i] = 1e9;
    
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            scanf("%d", &w[i][j]);
    int ans = 1e9;

    /*MST */
    ini();
    #define ar3 array<int, 3>
    vector<ar3> u;
    for (int i = k + 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) 
            u.pb({w[i][j], i, j});
    
    sort(u.begin(), u.end());
    for (auto s : u) {
        if (gfa(s[1]) == gfa(s[2])) continue;
        lk(s[1], s[2]);
        p[++cnt] = th(s[1], s[2], s[0]);
    }
    for (int i = 1; i <= k; i++)
        for (int j = k + 1; j <= n; j++)
            p[++cnt] = th(i, j, w[i][j]);
    
    for (int i = 0; i < (1 << (k * (k - 1) / 2)); i++) {
        ini();
        preg.clear();
        memset(cd, 0, sizeof(cd));
        nans = 0;
        int ncnt = 0;
        for (int u = 1; u <= k; u++) 
            for (int v = u + 1; v <= k; v++) {
                if (i & (1 << ncnt)) preg.pb(mp(u, v));
                ncnt += 1;
            }
        int flag = 1;
        for (auto s : preg) {
            if (gfa(s.fi) == gfa(s.se)) flag = 0;
            lk(s.fi, s.se);
            nans += inf - w[s.fi][s.se];
            cd[s.fi] += 1, cd[s.se] += 1;
        }
        for (int i = 1; i <= k; i++)
            if (cd[i] > d[i]) flag = 0;
        if (!flag) continue;
        //if (i == 0) cout << "!!!" << flag << endl;
        memset(fl, 0, sizeof(fl));
        for (int m = 0; m < n - 1 - preg.size(); m++) {
            flag &= bfs();
            //cout << "???" << flag << endl;
            if (!flag) break;
        }
        if (flag) {
            //cout << "??? " << i << ' ' << nans << endl;
            chkmin(ans, (n - 1) * inf - nans);
        }
    }
    cout << ans << endl;
    return (0-0); // <3
}
/*
1
10
8 6 2 9 10 4 5 1 3 7

*/