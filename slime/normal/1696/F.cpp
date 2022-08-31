//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 3
#define S 20
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 105;
vector<pi> edges;
int dis[maxn][maxn];
int sm[maxn][maxn][maxn]; // x, y to z same
char inp[maxn];
int adj[maxn][maxn];
int n;
int flag = 1;
void ade(int u, int v) {
    edges.pb(mp(u, v));
    adj[u][v] = adj[v][u] = 1;
}
int cnt[maxn];
int hv[maxn][maxn];
int inq[maxn];
void workchain(vi a) {
    if (!flag) return ;
    if (a.size() <= 2) {
        if (a.size() == 2) 
            ade(a[0], a[1]);
        return ;
    }
    memset(cnt, 0, sizeof(cnt));
    for (auto u : a)
        for (auto v : a) {
            if (v >= u) continue;
            for (auto k : a)
                if (sm[u][v][k])
                    cnt[k] += 1;
        }
    vector<pi> cs;
    for (auto v : a)
        cs.pb(mp(cnt[v], v));
    sort(cs.begin(), cs.end());
    int start = cs[0].se, ee = 0;
    for (auto u : a) {
        if (cnt[u] != 1) continue;
        for (auto v : a) 
            if (sm[start][v][u])
                ee = u;
    }
    if (!ee) {
        flag = 0;
        return ;
    }
    //cout << ee << endl;
    for (auto u : a)
        inq[u] = 0;
    vi cur; cur.pb(start), cur.pb(ee);
    inq[start] = 1, inq[ee] = 1;
    while (1) {
        int nx = 0;
        for (auto v : a) {
            if (inq[v]) continue;
            if (sm[start][v][ee]) nx = v;
        }
        if (!nx) break;
        inq[nx] = 1, cur.pb(nx);
        start = ee;
        ee = nx;
    }
    if (cur.size() != a.size())
        flag = 0;
    else 
        for (int i = 0; i + 1 < (int)cur.size(); i++)
            ade(cur[i], cur[i + 1]);
}
void work(vi a) {
    if (a.size() <= 1) return ;
    if (a.size() == 2) {
        ade(a[0], a[1]);
        return ;
    }
    if (!flag) return ;
    int mxi = -1, mxj = -1, mans = -1;
    for (auto i : a)
        for (auto j : a) {
            if (i >= j) continue;
            int cnt = 0;
            for (auto k : a) 
                if (sm[i][j][k]) cnt += 1;
            if (chkmax(mans, cnt)) mxi = i, mxj = j;
        }
    if (mxi == -1) {
        flag = 0;
        return ;
    }
    vi nxt, rem;
    for (auto k : a)
        if (sm[mxi][mxj][k]) nxt.pb(k);
        else rem.pb(k);
    if (nxt.size() == a.size()) {
        flag = 0;
        return ;
    }
    if (nxt.size() == 0) {
        flag = 0;
        return ;
    }
    work(nxt);
    int cen = 0;
    if (nxt.size() == 1) cen = nxt[0];
    else {
        for (auto a : nxt) {
            for (auto b : nxt) {
                if (!adj[a][b]) continue;
                for (auto c : rem)
                    if (sm[a][c][b]) cen = b;
            }
        }
    }
    if (cen == 0) flag = 0;
    else {
        rem.pb(cen);
        workchain(rem);
    }
}
void check() {
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++)
            dis[i][j] = 1e9;
        dis[i][i] = 0;
    }
    for (auto x : edges)
        dis[x.fi][x.se] = dis[x.se][x.fi] = 1;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                chkmin(dis[i][j], dis[i][k] + dis[k][j]);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int k = 1; k <= n; k++) {
                int cur = (dis[i][k] == dis[j][k]);
                if (cur != sm[i][j][k]) flag = 0;
            }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(adj, 0, sizeof(adj));
        cin >> n;
        flag = 1;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                scanf("%s", inp + 1);
                for (int k = 1; k <= n; k++) {
                    sm[i][j][k] = sm[j][i][k] = inp[k] - '0';
                    if (k == i || k == j)
                        if (sm[i][j][k]) flag = 0;
                }
            }
        }
        edges.clear();
        vi cur(n);
        for (int i = 0; i < n; i++)
            cur[i] = i + 1;
        work(cur);
        check();
        if (flag) {
            cout << "Yes" << endl;
            for (auto v : edges)
                cout << v.fi << ' ' << v.se << endl;
        }
        else cout << "No" << endl;

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