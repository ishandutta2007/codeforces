#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int N = 3e5 + 10;
int n, m;
vector<int> g[N];

void read() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

set<int> ans;

bool used[N];

void dfs(int v) {
    used[v] = true;
    ans.insert(v);
    for (auto i : g[v]) {
        if (ans.count(i)) {
            ans.erase(v);
            break;
        }
    }
    for (auto i : g[v]) {
        if (!used[i]) {
            dfs(i);
        }
    }
}

void dfsAns(int v) {
    used[v] = true;
    for (auto i : g[v]) {
        if (used[i]) continue;
        if (!ans.count(v) && !ans.count(i)) continue;
        dfsAns(i);
    }
}

bool check() {
    fill(used, used + n, false);
    dfsAns(0);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) return false;
    }
    return true;
}

void run() {
    ans.clear();
    if (n > m + 1) return;
    fill(used, used + n, false);
    dfs(0);
    if (check()) return;
    ans.clear();
    fill(used, used + n, false);
    for (auto i : g[0]) {
        dfs(i);
        if (check()) return;
        ans.clear();
        break;
    }
}

void write() {
    if (ans.empty()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << ans.size() << '\n';
        for (auto i : ans) {
            cout << i + 1 << " ";
        }
        cout << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        read();
        run();
        write();
    }
    return 0;
}