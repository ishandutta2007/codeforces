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

int t = 0, maxT = 0;
vector<int> adj[100005];
vector<pair<int, int>> ret;

void dfs(int u, int p, int pt) {
    ret.emplace_back(u, t);
    int deg = (int) adj[u].size() - (p != -1);
    for (int v : adj[u])
        if (v != p) {
            if (t == maxT) {
                t = pt - deg - 1;
                ret.emplace_back(u, t);
            }
            t++;
            dfs(v, u, t);
            ret.emplace_back(u, t);
            deg--;
        }
    if (p != -1 && t >= pt) {
        t = pt - 1;
        ret.emplace_back(u, t);
    }
    t++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i=0; i<n; i++)
        maxT = max(maxT, (int) adj[i].size());
    dfs(0, -1, -1);
    cout << ret.size() << "\n";
    for (auto &p : ret)
        cout << p.first + 1 << " " << p.second << "\n";

    return 0;
}