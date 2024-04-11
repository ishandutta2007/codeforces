#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int N = 2e5 + 10;
const int LOG = 18;

int n;
vector<int> g[N];

int jump[N][LOG];
int order[2 * N];
int sparse[2 * N][LOG + 1];
int tin[N], timer = 0;
int h[N];
int lg[2 * N];

bool used[N];
int sz[N];
int centr;

int par[N];
int indSon[N];
ll myDist[N];
vector<ll> sumDist[N];
int myCnt[N];
vector<int> sumCnt[N];

int vL[N], rL[N], vR[N], rR[N];
ll suffR[N];

ll ans;

void read() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(i + n);
        g[v].push_back(i + n);
        g[i + n].push_back(u);
        g[i + n].push_back(v);
    }
}

void dfsLCA(int v, int p) {
    tin[v] = timer;
    order[timer++] = v;
    jump[v][0] = p;
    for (int i = 1; i < LOG; ++i) {
        jump[v][i] = jump[jump[v][i - 1]][i - 1];
    }
    for (auto i : g[v]) {
        if (i == p) continue;
        h[i] = h[v] + 1;
        order[timer++] = v;
        dfsLCA(i, v); 
    }
}

int goUp(int v, int h) {
    for (int i = 0; i < LOG; ++i) {
        if ((h >> i) & 1) {
            v = jump[v][i];
        }
    }
    return v;
}

int merge(int v, int u) {
    if (h[v] < h[u]) {
        return v;
    } else {
        return u;
    }
}

int lca(int v, int u) {
    int l = tin[v];
    int r = tin[u];
    if (l > r) swap(l, r);
    int log = lg[r - l];
    int ans = merge(sparse[l][log], sparse[r - (1 << log) + 1][log]);
    return ans;
}

int dist(int v, int u) {
    return h[v] + h[u] - 2 * h[lca(v, u)]; 
}

void dfsCentroid(int v, int p, int size) {
    sz[v] = 1;
    int mx = 0;
    for (auto i : g[v]) {
        if (used[i]) continue;
        if (i == p) continue;
        dfsCentroid(i, v, size);
        sz[v] += sz[i];
        chkmax(mx, sz[i]);
    }
    chkmax(mx, size - sz[v]);
    if (mx * 2 <= size) {
        centr = v;
    }
}

void buildCentroid(int v, int p, int ind, int size) {
    centr = -1;
    dfsCentroid(v, -1, size);
    v = centr;
    assert(v != -1);
    par[v] = p;
    indSon[v] = ind;
    used[v] = true;
    int it = 0;

    for (auto i : g[v]) {
        if (used[i]) continue;
        int fsz = sz[i];
        if (fsz > sz[v]) {
            fsz = size - sz[v];
        }
        buildCentroid(i, v, it++, fsz);    
    }

    sumDist[v].assign(it, 0);
    sumCnt[v].assign(it, 0);
}

void build() {
    dfsLCA(0, 0);
    for (int i = 2; i < 2 * N; ++i) {
        lg[i] = lg[i / 2] + 1;
    }
    for (int i = 0; i < timer; ++i) {
        sparse[i][0] = order[i];
    }
    for (int l = 1; l <= LOG; ++l) {
        for (int i = 0; i + (1 << l) <= timer; ++i) {
            sparse[i][l] = merge(sparse[i][l - 1], sparse[i + (1 << (l - 1))][l - 1]);
        }
    }
    buildCentroid(0, -1, -1, 2 * n - 1);
}

int goPath(int v, int u, int len) {
    int l = lca(v, u);
    if (h[v] - h[l] < len) {
        v = goUp(u, dist(v, u) - len);
    } else {
        v = goUp(v, len);
    }
    return v;
}

bool checkIn(int v1, int r1, int v2, int r2) {
    return dist(v1, v2) <= r1 - r2;
}

tuple<int, int> merge(int v1, int r1, int v2, int r2) {
    if (dist(v1, v2) <= max(r1, r2) - min(r1, r2)) {
        if (r2 > r1) {
            v1 = v2;
            r1 = r2;
        }
    } else {
        int R = dist(v1, v2) + r1 + r2;
        assert(R % 2 == 0);
        R /= 2;
        int V = goPath(v1, v2, R - r1);
        v1 = V;
        r1 = R;
    }
    return {v1, r1};
}

void addV(int v) {
    int u = v;
    int myInd = -1;
    while (u != -1) {
        myDist[u] += dist(u, v);
        myCnt[u]++;
        if (myInd != -1) {
            sumDist[u][myInd] += dist(u, v);
            sumCnt[u][myInd]++;
        }
        myInd = indSon[u];
        u = par[u];
    }
}

void delV(int v) {
    int u = v;
    int myInd = -1;
    while (u != -1) {
        myDist[u] -= dist(u, v);
        myCnt[u]--;
        if (myInd != -1) {
            sumDist[u][myInd] -= dist(u, v);
            sumCnt[u][myInd]--;
        }
        myInd = indSon[u];
        u = par[u];
    }
}

ll getAns(int v) {
    ll ans = 0;
    int u = v;
    int myInd = -1;
    while (u != -1) {
        ans += myDist[u];
        ans += (ll) myCnt[u] * dist(u, v);
        if (myInd != -1) {
            ans -= sumDist[u][myInd];
            ans -= (ll) sumCnt[u][myInd] * dist(u, v);
        }
        myInd = indSon[u];
        u = par[u];
    }
    return ans;
}

void solve(int l, int r) {
    if (l + 1 >= r) return;
    int m = (l + r) / 2;
    solve(l, m);
    solve(m, r);
    for (int i = 0; i < m - l; ++i) {
        vL[i] = m - 1 - i;
        rL[i] = 0;
        if (i > 0) {
            tie(vL[i], rL[i]) = merge(vL[i], rL[i], vL[i - 1], rL[i - 1]);
        }
    }
    for (int i = 0; i < r - m; ++i) {
        vR[i] = m + i;
        rR[i] = 0;
        if (i > 0){
            tie(vR[i], rR[i]) = merge(vR[i], rR[i], vR[i - 1], rR[i - 1]);
        }
    }
    for (int i = r - m - 1; i >= 0; --i) {
        suffR[i] = rR[i];
        if (i != r - m - 1) {
            suffR[i] += suffR[i + 1];
        }
    }
    int L = 0;
    int R = 0;
    for (int i = 0; i < m - l; ++i) {
        while (R < r - m && !checkIn(vR[R], rR[R], vL[i], rL[i])) {
            addV(vR[R]);
            ++R;
        }
        while (L < R && checkIn(vL[i], rL[i], vR[L], rR[L])) {
            delV(vR[L]);
            ++L;
        }
        ans += (ll)L * rL[i] * 2;
        if (R < r - m) {
            ans += suffR[R] * 2;
        }
        if (R - L > 0) {
            ans += suffR[L];
            if (R < r - m) {
                ans -= suffR[R];
            }
        }
        ans += (ll) rL[i] * (R - L);
        ans += getAns(vL[i]);
    }
    while (L < R) {
        delV(vR[L]);
        ++L;
    }
}

void solve() {
    ans = 0;
    solve(0, n);
}

void run() {
    build();
    solve();
}

void write() {
    assert(ans % 2 == 0);
    cout << ans / 2 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}