#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int t[500000], has[500000];
bool on[500000];
vector<int> adj[500000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=0; i<n; i++)
        cin >> t[i];

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [] (int u, int v) {
        return t[u] < t[v];
    });

    memset(has, -1, sizeof(has));
    for (int i=0; i<n; i++) {
        int cur = 1, u = p[i];
        for (int v : adj[u])
            if (on[v])
                has[t[v]] = i;
        DEBUG(u, has)
        while (cur <= t[u] && has[cur] == i)
            cur++;
        DEBUG(cur)
        if (cur != t[u]) {
            cout << "-1\n";
            return 0;
        }
        on[u] = true;
    }

    for (int i=0; i<n; i++)
        cout << p[i] + 1 << " \n"[i==n-1];

    return 0;
}