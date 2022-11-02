#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

struct Edge{
    int to, id;
};

const int N = 1e5 + 10;
int n, m;

vector<Edge> g[N];
int edges[N][2];

void no() {
    cout << "No solution\n";
    exit(0);
}

int ans[N][2];

int topAns = 0;

bool used[N];
bool blocked[N];

int dfs(int v) {
    vector<Edge> adjacent;

    for (auto [to, id] : g[v]) {
        if (blocked[id]) continue;
        adjacent.push_back({to, id});
        blocked[id] = true;
    }

    int last = -1;
    for (auto [to, id] : adjacent) {
        int have = dfs(to);
        if (have != -1) {
            ans[topAns][0] = id;
            ans[topAns][1] = have;
            ++topAns;
        } else {
            if (last != -1) {
                ans[topAns][0] = last;
                ans[topAns][1] = id;
                ++topAns;
                last = -1;
            } else {
                last = id;
            }
        }
    }
    return last;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> m;
    if (m & 1) {
        no();
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
        edges[i][0] = u;
        edges[i][1] = v;
    }
    assert(dfs(0) == -1);
    // cerr << "topAns = " << topAns << endl;

    for (int i = 0; i < topAns; ++i) {
        int a = edges[ans[i][0]][0];
        int b = edges[ans[i][0]][1];
        if (a == edges[ans[i][1]][0] || a == edges[ans[i][1]][1]) {
            swap(a, b);
        }
        int c = b ^ edges[ans[i][1]][0] ^ edges[ans[i][1]][1];
        cout << a + 1 << " " << b + 1 << " " << c + 1 << '\n';
    }
    // cout.flush();
    // assert(topAns == m / 2);

    return 0;
}