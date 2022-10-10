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

const int MAXN = 2e5 + 5;

int maxD, a[MAXN], par[MAXN];
long long dp[MAXN], best[MAXN];
vector<int> adj[MAXN], depth[MAXN];

void dfs(int u, int d) {
    maxD = max(maxD, d);
    depth[d].push_back(u);
    for (int v : adj[u])
        if (v != par[u]) {
            par[v] = u;
            dfs(v, d + 1);
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++) {
            adj[i].clear();
            depth[i].clear();
            dp[i] = 0;
        }
        for (int i=1; i<n; i++) {
            int v;
            cin >> v;
            v--;
            adj[i].push_back(v);
            adj[v].push_back(i);
        }
        for (int i=1; i<n; i++)
            cin >> a[i];

        maxD = 0;
        par[0] = -1;
        dfs(0, 0);
        vector<long long> suff;
        for (int j=maxD; j>=0; j--) {
            if (j < maxD) {
                long long pref = LLONG_MIN;
                for (int i=0; i<(int)depth[j+1].size(); i++) {
                    best[depth[j+1][i]] = suff[i] - a[depth[j+1][i]];
                    if (i > 0)
                        best[depth[j+1][i]] = max(best[depth[j+1][i]], pref + a[depth[j+1][i]]);
                    pref = max(pref, dp[depth[j+1][i]] - a[depth[j+1][i]]);
                }
                for (int u : depth[j])
                    for (int v : adj[u])
                        if (v != par[u])
                            dp[u] = max({dp[u], best[v], dp[v] + max(a[v] - a[depth[j+1][0]], a[depth[j+1].back()] - a[v])});
            }
            sort(depth[j].begin(), depth[j].end(), [] (int u, int v) {
                return tie(a[u], u) < tie(a[v], v);
            });
            suff.clear();
            for (int i=(int)depth[j].size()-1; i>=0; i--)
                suff.push_back(max(suff.empty() ? LLONG_MIN : suff.back(), a[depth[j][i]] + dp[depth[j][i]]));
            reverse(suff.begin(), suff.end());
        }
        cout << dp[0] << "\n";
    }

    return 0;
}