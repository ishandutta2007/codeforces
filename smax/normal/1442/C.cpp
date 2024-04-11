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

typedef tuple<int, int, int, int> ti;

const int MAX = 2e5 + 5;
const int LOG = 20;
const int MOD = 998244353;

int dist1[MAX][LOG];
bool vis1[MAX][LOG], vis2[MAX][2];
pair<int, int> dist2[MAX][2];
vector<int> adj[MAX][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u][0].push_back(v);
        adj[v][1].push_back(u);
    }

    // Case 1: Consider k <= log2(m)
    memset(dist1, 127, sizeof(dist1));
    int INF = dist1[0][0];
    deque<pair<int, int>> dq;
    dist1[0][0] = 0;
    dq.emplace_back(0, 0);
    while (!dq.empty()) {
        auto [u, k] = dq.front();
        dq.pop_front();
        if (vis1[u][k])
            continue;
        vis1[u][k] = true;
        if (k + 1 < LOG && dist1[u][k] < dist1[u][k+1]) {
            dist1[u][k+1] = dist1[u][k];
            dq.emplace_front(u, k + 1);
        }
        for (int v : adj[u][k%2])
            if (dist1[u][k] + 1 < dist1[v][k]) {
                dist1[v][k] = dist1[u][k] + 1;
                dq.emplace_back(v, k);
            }
    }

    int ret = INF;
    for (int j=0; j<LOG; j++)
        ret = min(ret, dist1[n-1][j] + (1 << j) - 1);
    if (ret < INF) {
        cout << ret << "\n";
        return 0;
    }

    // Case 2: Consider k > log2(m)
    for (int i=0; i<n; i++)
        for (int j=0; j<2; j++)
            dist2[i][j] = {INT_MAX, INT_MAX};
    priority_queue<ti, vector<ti>, greater<ti>> pq;
    dist2[0][0] = {0, 0};
    pq.emplace(0, 0, 0, 0);
    while (!pq.empty()) {
        auto [k, d, u, f] = pq.top();
        pq.pop();
        if (vis2[u][f])
            continue;
        vis2[u][f] = true;
        if (make_pair(k + 1, d) < dist2[u][!f]) {
            dist2[u][!f] = {k + 1, d};
            pq.emplace(k + 1, d, u, !f);
        }
        for (int v : adj[u][f])
            if (make_pair(k, d + 1) < dist2[v][f]) {
                dist2[v][f] = {k, d + 1};
                pq.emplace(k, d + 1, v, f);
            }
    }

    pair<int, int> best = min(dist2[n-1][0], dist2[n-1][1]);
    ret = 1;
    for (int i=0; i<best.first; i++)
        ret = ret * 2 % MOD;
    cout << ((ret + MOD - 1) % MOD + best.second) % MOD << "\n";

    return 0;
}