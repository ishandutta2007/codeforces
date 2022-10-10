#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

typedef pair<long long, long long> pll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int id = 0;
    map<pll, int> mp;
    vector<pair<pll, pll>> pts;
    for (int i=0; i<n; i++) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        pll p(b * c, (a + b) * d);
        long long g = __gcd(p.first, p.second);
        p.first /= g;
        p.second /= g;
        if (!mp.count(p))
            mp[p] = id++;
        pll q(b * (c + d), a * d);
        g = __gcd(q.first, q.second);
        q.first /= g;
        q.second /= g;
        if (!mp.count(q))
            mp[q] = id++;
        pts.emplace_back(p, q);
    }

    vector<vector<pair<int, int>>> adj(id);
    for (int i=0; i<n; i++) {
        adj[mp[pts[i].first]].emplace_back(mp[pts[i].second], i);
        adj[mp[pts[i].second]].emplace_back(mp[pts[i].first], i);
    }

    vector<pair<int, int>> ret;
    vector<int> depth(id);
    vector<bool> vis(id);

    auto dfs = [&] (auto &self, int u, int p) -> int {
        vis[u] = true;
        vector<int> all;
        for (auto [v, i] : adj[u])
            if (i != p) {
                if (vis[v]) {
                    if (depth[v] < depth[u])
                        all.push_back(i);
                } else {
                    depth[v] = depth[u] + 1;
                    int cur = self(self, v, i);
                    if (cur != -1)
                        all.push_back(cur);
                }
            }
        if (p != -1)
            all.push_back(p);
        for (int i=0; i+1<(int)all.size(); i+=2)
            ret.emplace_back(all[i], all[i+1]);
        return all.size() % 2 ? all.back() : -1;
    };

    for (int u=0; u<id; u++)
        if (!vis[u])
            dfs(dfs, u, -1);

    cout << ret.size() << "\n";
    for (auto [a, b] : ret)
        cout << a + 1 << " " << b + 1 << "\n";

    return 0;
}