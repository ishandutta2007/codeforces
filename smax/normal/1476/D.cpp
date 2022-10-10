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

const int MAXN = 3e5 + 5;

int id, comp[MAXN][2], uniq[MAXN], sz[2*MAXN];
vector<pair<int, int>> adj[MAXN][2];

int dfs(int u, int b) {
    int ret = 0;
    comp[u][b] = id;
    if (uniq[u] != id) {
        uniq[u] = id;
        ret++;
    }
    for (auto [v, c] : adj[u][b])
        if (comp[v][c] == -1)
            ret += dfs(v, c);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        id = 0;
        memset(uniq, -1, sizeof(int) * (n + 1));
        for (int i=0; i<=n; i++)
            for (int j=0; j<2; j++) {
                comp[i][j] = -1;
                adj[i][j].clear();
                if (i > 0 && ((s[i-1] == 'L') ^ j))
                    adj[i][j].emplace_back(i - 1, j ^ 1);
                if (i < n && ((s[i] == 'R') ^ j))
                    adj[i][j].emplace_back(i + 1, j ^ 1);
            }

        for (int i=0; i<=n; i++) {
            if (comp[i][0] == -1) {
                sz[id] = dfs(i, 0);
                id++;
            }
            cout << sz[comp[i][0]] << " ";
        }
        cout << "\n";
    }

    return 0;
}