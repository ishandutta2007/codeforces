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

const int MAXN = 2e5 + 5;

int deg[MAXN], dp[MAXN][2];
vector<int> adj[MAXN];

// 1 means path sticking up through u
void dfs(int u, int p) {
    int mn = INT_MAX, mnIdx = -1, mn2 = INT_MAX, mnIdx2 = -1, tot = 0;
    for (int v : adj[u])
        if (v != p) {
            dfs(v, u);
            int x = dp[v][1] - min(dp[v][0], dp[v][1]);
            if (x <= mn) {
                mn2 = mn;
                mnIdx2 = mnIdx;
                mn = x;
                mnIdx = v;
            } else if (x < mn2) {
                mn2 = x;
                mnIdx2 = v;
            }
            tot += min(dp[v][0], dp[v][1]);
        }
    // case 1: start new path
    dp[u][1] = tot + 1;
    // case 2: continue off single path
    if (mnIdx != -1)
        dp[u][1] = min(dp[u][1], tot - min(dp[mnIdx][0], dp[mnIdx][1]) + dp[mnIdx][1]);
    dp[u][0] = dp[u][1];
    // case 3: join two paths coming up
    if (mnIdx != -1 && mnIdx2 != -1)
        dp[u][0] = min(dp[u][0], tot - min(dp[mnIdx][0], dp[mnIdx][1]) - min(dp[mnIdx2][0], dp[mnIdx2][1]) + dp[mnIdx][1] + dp[mnIdx2][1] - 1);
    DEBUG(u, tot, dp[u][0], dp[u][1])
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x, y;
    cin >> n >> x >> y;
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    if (x < y) {
        dfs(0, -1);
        DEBUG(dp[0][0])
        cout << (dp[0][0] - 1) * y + (n - dp[0][0]) * x << "\n";
    } else if (find(deg, deg + n, n - 1) == deg + n) {
        cout << (n - 1) * y << "\n";
    } else {
        cout << (n - 2) * y + x << "\n";
    }

    return 0;
}