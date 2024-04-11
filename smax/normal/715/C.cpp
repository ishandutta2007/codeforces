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

int mod, sz[100005];
long long power[100005], inv[100005];
bool visited[100005];
vector<pair<int, int>> adj[100005];
map<long long, int> upMp, downMp;

long long inverse(long long a) {
    long long m = mod, x = 1, y = 0;
    while (a > 1) {
        long long q = a / m, t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += mod;
    return x;
}

int dfsSz(int u, int p) {
    sz[u] = 1;
    for (auto &e : adj[u])
        if (e.first != p && !visited[e.first])
            sz[u] += dfsSz(e.first, u);
    return sz[u];
}

int dfsCentroid(int u, int p, int s) {
    for (auto &e : adj[u])
        if (e.first != p && !visited[e.first] && sz[e.first] > s / 2)
            return dfsCentroid(e.first, u, s);
    return u;
}

long long dfsMatch(int u, int p, long long up, long long down, int depth) {
    long long ret = (downMp.count(up) ? downMp[up] : 0) + (upMp.count((mod - down) * inv[depth] % mod) ? upMp[(mod - down) * inv[depth] % mod] : 0) + (up == 0) + (down == 0);
    for (auto &e : adj[u])
        if (e.first != p && !visited[e.first])
            ret += dfsMatch(e.first, u, (up + power[depth] * e.second) % mod, (10 * down + e.second) % mod, depth + 1);
    return ret;
}

void dfsFill(int u, int p, long long up, long long down, int depth) {
    upMp[up]++;
    downMp[(mod - down) * inv[depth] % mod]++;
    for (auto &e : adj[u])
        if (e.first != p && !visited[e.first])
            dfsFill(e.first, u, (up + power[depth] * e.second) % mod, (10 * down + e.second) % mod, depth + 1);
}

long long dfsMain(int u) {
    u = dfsCentroid(u, -1, dfsSz(u, -1));
    upMp.clear();
    downMp.clear();
    long long ret = 0;
    for (auto &e : adj[u])
        if (!visited[e.first]) {
            ret += dfsMatch(e.first, u, e.second % mod, e.second % mod, 1);
            dfsFill(e.first, u, e.second % mod, e.second % mod, 1);
        }

    visited[u] = true;
    for (auto &e : adj[u])
        if (!visited[e.first])
            ret += dfsMain(e.first);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n >> mod;
    for (int i=0; i<n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    int inv10 = inverse(10);
    power[0] = inv[0] = 1;
    for (int i=1; i<=n; i++) {
        power[i] = power[i-1] * 10 % mod;
        inv[i] = inv[i-1] * inv10 % mod;
    }

    cout << dfsMain(0) << "\n";

    return 0;
}