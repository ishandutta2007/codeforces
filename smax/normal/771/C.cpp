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

int k;
long long dp[200000][5], numPaths[200000][5];
vector<int> adj[200000];

void dfsInit(int u, int p) {
    for (int v : adj[u])
        if (v != p) {
            dfsInit(v, u);
            for (int i=0; i<k; i++) {
                dp[u][(i+1)%k] += dp[v][i] + (i == 0 ? numPaths[v][i] + 1 : 0);
                numPaths[u][(i+1)%k] += numPaths[v][i] + (i == 0);
            }
        }
}

long long dfsReroot(int u, int p) {
    long long ret = 0;
    for (int i=0; i<k; i++)
        ret += dp[u][i%k];

    for (int v : adj[u])
        if (v != p) {
            for (int i=0; i<k; i++) {
                dp[u][(i+1)%k] -= dp[v][i] + (i == 0 ? numPaths[v][i] + 1 : 0);
                numPaths[u][(i+1)%k] -= numPaths[v][i] + (i == 0);
            }
            for (int i=0; i<k; i++) {
                dp[v][(i+1)%k] += dp[u][i] + (i == 0 ? numPaths[u][i] + 1 : 0);
                numPaths[v][(i+1)%k] += numPaths[u][i] + (i == 0);
            }

            ret += dfsReroot(v, u);

            for (int i=0; i<k; i++) {
                dp[v][(i+1)%k] -= dp[u][i] + (i == 0 ? numPaths[u][i] + 1 : 0);
                numPaths[v][(i+1)%k] -= numPaths[u][i] + (i == 0);
            }
            for (int i=0; i<k; i++) {
                dp[u][(i+1)%k] += dp[v][i] + (i == 0 ? numPaths[v][i] + 1 : 0);
                numPaths[u][(i+1)%k] += numPaths[v][i] + (i == 0);
            }
        }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n >> k;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    dfsInit(0, -1);
    cout << dfsReroot(0, -1) / 2 << "\n";

    return 0;
}