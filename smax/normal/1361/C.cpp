#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

#define MAXN 1000005
#define BIT 20

int n, id, pos[MAXN + (1 << BIT)];
bool visited[MAXN + (1 << BIT)];
vector<pair<int, int>> adj[MAXN + (1 << BIT)];
stack<int> st;

void dfs(int u) {
    visited[u] = true;
    for (auto &e : adj[u])
        if (!visited[e.first])
            dfs(e.first);
}

bool ok(int b) {
    bool comp = false;
    for (int i=0; i<1<<b; i++) {
        if ((int) adj[MAXN + i].size() % 2)
            return false;
        if (!visited[MAXN + i] && !adj[MAXN + i].empty()) {
            if (comp)
                return false;
            comp = true;
            dfs(MAXN + i);
        }
    }
    return comp;
}

vector<int> eulerPath(int b) {
    for (int i=0; i<2*n; i++)
        pos[i] = 0;
    for (int i=0; i<1<<b; i++)
        pos[MAXN + i] = 0;
    for (int i=0; i<id; i++)
        visited[i] = false;

    vector<int> ret;
    st.push(0);
//    degree[s]++;    // comment out to find tour instead of path
    while (!st.empty()) {
        int u = st.top();
        if (pos[u] == (int) adj[u].size()) {
            if (u < MAXN) ret.push_back(u);
            st.pop();
            continue;
        }

        auto e = adj[u][pos[u]++];
        if (!visited[e.second]) {
            st.push(e.first);
            visited[e.second] = true;
        }
    }

    assert((int) ret.size() > 2 * n);
    if (ret[1] == 1)
        ret.pop_back();
    else
        ret.erase(ret.begin());
    return ret;
}

int in[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i=0; i<n; i++)
        cin >> in[2*i] >> in[2*i+1];

    for (int b=BIT; b>=0; b--) {
        for (int i=0; i<2*n; i++) {
            adj[i].clear();
            visited[i] = false;
        }
        for (int i=0; i<1<<b; i++) {
            adj[MAXN + i].clear();
            visited[MAXN + i] = false;
        }
        id = 0;
        for (int i=0; i<2*n; i+=2) {
            int u = in[i] & ((1 << b) - 1), v = in[i+1] & ((1 << b) - 1);
            adj[MAXN + u].emplace_back(i, id);
            adj[i].emplace_back(MAXN + u, id++);
            adj[MAXN + v].emplace_back(i + 1, id);
            adj[i + 1].emplace_back(MAXN + v, id++);
            adj[i].emplace_back(i + 1, id);
            adj[i + 1].emplace_back(i, id++);
        }
        if (ok(b)) {
            vector<int> ret = eulerPath(b);
            cout << b << "\n";
            for (int u : ret)
                cout << u + 1 << " ";
            cout << "\n";
            return 0;
        }
    }
    assert(false);

    return 0;
}