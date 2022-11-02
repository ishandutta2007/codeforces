#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int N = 2e5 + 10;

int n, m, s;
vector<int> g[N];

void no() {
    cout << "Impossible" << endl;
    exit(0);
}

int par[N];
int color[N];

void output(int t, int from2) {
    vector<int> path1, path2;
    int cur;
    cur = t;
    while (cur != s) {
        path1.push_back(cur);
        cur = par[cur];
    }
    path1.push_back(s);
    reverse(all(path1));
    path2.push_back(t);
    cur = from2;
    while (cur != s) {
        path2.push_back(cur);
        cur = par[cur];
    }
    path2.push_back(s);
    reverse(all(path2));
    cout << "Possible\n";
    cout << path1.size() << '\n';
    for (auto i : path1) {
        cout << i + 1 << ' ';
    } 
    cout << '\n';
    cout << path2.size() << '\n';
    for (auto i : path2) {
        cout << i + 1 << ' ';
    }
    cout << '\n';
    exit(0);
}

void dfs(int v, int c) {
    color[v] = c;
    for (auto to : g[v]) {
        if (to == s) continue;
        if (color[to] == c) continue;
        if (color[to] == -1) {
            par[to] = v;
            dfs(to, c);
        } else {
            output(to, v);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> m >> s;
    --s;
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        --from;
        --to;
        g[from].push_back(to);
    }
    fill(par, par + N, -1);
    fill(color, color + N, -1);
    int c = 0;
    for (auto to : g[s]) {
        if (color[to] != -1) {
            output(to, s);
        }    
        par[to] = s;
        dfs(to, c++);
    }
    // for (int i = 0; i < n; ++i) {
    //     cout << color[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; ++i) {
    //     cout << par[i] << " ";
    // }
    // cout << endl;
    no();
    return 0;
}