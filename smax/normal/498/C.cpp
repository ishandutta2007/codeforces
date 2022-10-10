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

const int MAX = 3005;

namespace matching {
    int n, matchL[MAX], matchR[MAX], dist[MAX];
    vector<int> adj[MAX];

    bool bfs() {
        queue<int> q;
        for (int i=1; i<=n; i++) {
            if (!matchL[i]) {
                dist[i] = 0;
                q.push(i);
            } else
                dist[i] = INT_MAX;
        }
        dist[0] = INT_MAX;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (dist[u] < dist[0])
                for (int v : adj[u])
                    if (dist[matchR[v]] == INT_MAX) {
                        dist[matchR[v]] = dist[u] + 1;
                        q.push(matchR[v]);
                    }
        }
        return dist[0] != INT_MAX;
    }

    bool dfs(int u) {
        if (u != 0) {
            for (int v : adj[u])
                if (dist[matchR[v]] == dist[u] + 1 && dfs(matchR[v])) {
                    matchL[u] = v;
                    matchR[v] = u;
                    return true;
                }
            dist[u] = INT_MAX;
            return false;
        }
        return true;
    }

    int mcbm() {
        int ret = 0;
        memset(matchL, 0, sizeof(matchL));
        memset(matchR, 0, sizeof(matchR));
        while (bfs())
            for (int i=1; i<=n; i++)
                if (!matchL[i] && dfs(i))
                    ret++;
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> pf, l(n), r(n);
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        l[i] = (int) pf.size();
        for (int p=2; p*p<=a; p++)
            while (a % p == 0) {
                pf.push_back(p);
                a /= p;
            }
        if (a > 1)
            pf.push_back(a);
        r[i] = (int) pf.size();
    }
    matching::n = (int) pf.size();
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (a % 2 == 0)
            swap(a, b);
        for (int j=l[a]; j<r[a]; j++)
            for (int k=l[b]; k<r[b]; k++)
                if (pf[j] == pf[k])
                    matching::adj[j+1].push_back(k+1);
    }
    cout << matching::mcbm() << "\n";

    return 0;
}