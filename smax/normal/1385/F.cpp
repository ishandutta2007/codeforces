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

int degree[200000];
vector<int> adj[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        memset(degree, 0, sizeof(int) * n);
        for (int i=0; i<n; i++)
            adj[i].clear();
        for (int i=0; i<n-1; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
            degree[x]++;
            degree[y]++;
        }

        queue<int> q;
        for (int i=0; i<n; i++)
            if (degree[i] == 1)
                q.push(i);

        int ret = 0;
        vector<int> cnt(n);
        vector<bool> visited(n);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            visited[u] = true;
            for (int v : adj[u])
                if (!visited[v] && ++cnt[v] == k) {
                    ret++;
                    cnt[v] = 0;
                    degree[v] -= k;
                    if (degree[v] == 1)
                        q.push(v);
                }
        }

        cout << ret << "\n";
    }

    return 0;
}