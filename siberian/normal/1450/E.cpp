#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int N = 210;
int n, m;
int d[N][N];
vector<int> g[N];

void read() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            d[i][j] = n;
        }
        d[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
        if (t == 0) {
            chkmin(d[u][v], 1);
            chkmin(d[v][u], 1);
        } else {
            chkmin(d[u][v], 1);
            chkmin(d[v][u], -1);
        }
    }
}

void no() {
    cout << "NO\n";
    exit(0);
}

int h[N];
bool used[N];

void dfs(int v) {
    used[v] = true;
    for (auto i : g[v]) {
        if (used[i]) {
            if (h[i] % 2 == h[v] % 2) {
                no();
            }
        } else {
            h[i] = h[v] + 1;
            dfs(i);
        }
    }
}

void check() {
    dfs(0);
}

int ans[N];
int dist[N];

void relax(int root) {
    for (int i = 0; i < n; ++i) {
        if (d[root][i] < 0) {
            return;
        }
    }
    for (int i = 0; i < n; ++i) {
        dist[i] = d[root][i];
    }
    int myMx = *max_element(dist, dist + n);
    int mx = *max_element(ans, ans + n);
    if (mx < myMx) {
        for (int i = 0; i < n; ++i) {
            ans[i] = dist[i];
        }
    }
}

void run() {
    check();
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                chkmin(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (d[i][i] < 0) {
            no();
        }
    } 
    ans[0] = -1;
    for (int i = 0; i < n; ++i) {
        relax(i);
    }
}

void write() {
    if (ans[0] == -1) no();
    cout << "YES\n";
    cout << *max_element(ans, ans + n) << "\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}