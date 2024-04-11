#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using matr = vector<vi>;

const int INF = 1e9 + 13;
const li INF64 = 4e18 + 13;
//const int M = 1e9 + 7;
const int M = 998244353;
const int N = 2e5 + 13;
const int LOGN = 30;

int sum(int a, int b) {
    a += b;

    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, n));
}

int p[N], sz[N];

int getp(int x) {
    return (x == p[x] ? x : p[x] = getp(p[x]));
}

void unite(int x, int y) {
    x = getp(x);
    y = getp(y);

    if(x == y)
        return;

    if(sz[x] < sz[y])
        swap(x, y);

    p[y] = x;
    sz[x] += sz[y];
}

vector<pii> g[N];
vector<pii> e;
//li ans = 0;
int tin[N], tout[N];
int T = 1;
int add1[N], add2[N];
bool res[N];
int go[N][LOGN];

void dfs1(int v, int par) {
    tin[v] = T++;

//    cout << "dfs1 " << v << ' ' << par << endl;

    go[v][0] = par;
    for(int i = 1; i < LOGN; i++) {
        go[v][i] = go[go[v][i - 1]][i - 1];
//        cout << v << ' ' << i << ' ' << go[v][i] << endl;
    }


    for(pii p : g[v]) {
        int u = p.f;

        if(u != par)
            dfs1(u, v);
    }

    tout[v] = T++;
}

bool is_anc(int anc, int v) {
    return (tin[anc] <= tin[v] && tout[v] <= tout[anc]);
}

void dfs2(int v, int par, int cur) {
    cur += add1[v];

    res[v] = (cur == e.size());

    for(pii p : g[v]) {
        int u = p.f;
        if(u != par)
            dfs2(u, v, cur + add2[v]);
    }

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        p[i] = i;
        sz[i] = 1;
    }

//    li res = 0;
//    pii root(-1, -1);

    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;



        if(getp(v) != getp(u)) {
//            res += i + 1;
            unite(v, u);
            g[v].emplace_back(u, i + 1);
            g[u].emplace_back(v, i + 1);
        } else {
            e.emplace_back(v, u);
//            root = {v, u};
        }
    }

    dfs1(0, 0);


    for(auto p : e) {
        int v = p.f, u = p.s;

        if(is_anc(u, v))
            swap(u, v);

        if(is_anc(v, u)) {
            add1[u]++;
            add1[0]++;
            int u1 = u;
//            cout << "jasgja " << v  << ' ' << u << endl;
            for(int k = LOGN - 1; k >= 0; k--)
                if(!is_anc(go[u1][k], v))
                    u1 = go[u1][k];
            add1[u1]--;
//            cout << " ---------- " << u1 << endl;
//            add2[v]--;
        } else {
            add1[v]++;
            add1[u]++;
        }
    }

    dfs2(0, -1, 0);

    for(int i = 0; i < n; i++)
        cout << res[i];
    cout << endl;

//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();
}