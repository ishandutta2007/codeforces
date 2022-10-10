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

const int MOD = 1e9 + 7;
const long long INF = 1e18;

void add(int &a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}

struct Line {
    long long m, c;

    Line(long long _m, long long _c) : m(_m), c(_c) {}

    long long eval(long long x) {
        return m * x + c;
    }

    bool intersect(Line &l1, Line &l2) {
        return (__int128) (c - l2.c) * (l1.m - l2.m) <= (__int128) (l2.c - l1.c) * (l2.m - m);
    }

    bool operator < (const Line &other) const {
        if (m == other.m)
            return c < other.c;
        return m < other.m;
    }

    friend ostream& operator << (ostream &os, const Line &l) {
        return os << l.m << "x + " << l.c;
    }
};

long long sum(long long a, long long b) {
    return (a + b) * (b - a + 1) / 2 % MOD;
}

long long dp[2005][2005];
pair<long long, int> best[2005];
vector<pair<int, int>> adj[2005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m, q;
    cin >> n >> m >> q;
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    best[0] = {0, 0};
    for (int i=1; i<n; i++)
        best[i] = {-INF, -1};
    int ret = 0;
    memset(dp, 128, sizeof(dp));
    dp[0][0] = 0;
    for (int i=0; i<m; i++) {
        for (int u=0; u<n; u++)
            for (auto &e : adj[u])
                dp[i+1][e.first] = max(dp[i+1][e.first], dp[i][u] + e.second);
        add(ret, *max_element(dp[i+1], dp[i+1] + n) % MOD);
        for (int j=0; j<n; j++)
            best[j] = max(best[j], {dp[i+1][j], i + 1});
    }

    vector<Line> lines;
    for (int i=0; i<n; i++) {
        int mx = 0;
        for (auto &e : adj[i])
            mx = max(mx, e.second);
        lines.emplace_back(mx, best[i].first - (long long) mx * best[i].second);
    }
    sort(lines.begin(), lines.end());

    vector<Line> hull;
    for (Line &l : lines) {
        while ((!hull.empty() && l.m == hull.back().m) || (hull.size() >= 2 && l.intersect(hull[(int) hull.size() - 2], hull.back())))
            hull.pop_back();
        hull.push_back(l);
    }

    long long pred = m + 1;
    for (int i=1; i<(int)hull.size(); i++) {
        if (pred > q)
            break;
        long long x = min((hull[i].c - hull[i-1].c) / (hull[i-1].m - hull[i].m), (long long) q);
        if (x < pred)
            continue;
        add(ret, (hull[i-1].m * sum(pred, x) % MOD + (hull[i-1].c % MOD + MOD) % MOD * (x - pred + 1) % MOD) % MOD);
        pred = x + 1;
    }
    if (pred <= q)
        add(ret, (hull.back().m * sum(pred, q) % MOD + (hull.back().c % MOD + MOD) % MOD * (q - pred + 1) % MOD) % MOD);

    cout << ret << "\n";

    return 0;
}