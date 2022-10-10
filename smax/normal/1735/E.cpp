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
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

struct Matching {
    int n, m;
    vector<int> matchL, matchR, dist;
    vector<vector<int>> adj;

    Matching(int _n, int _m) : n(_n), m(_m), matchL(n + 1), matchR(m + 1), dist(n + 1), adj(n + 1) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    bool bfs() {
        queue<int> q;
        for (int u=1; u<=n; u++) {
            if (!matchL[u]) {
                dist[u] = 0;
                q.push(u);
            } else {
                dist[u] = INT_MAX;
            }
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

    int solve() {
        int ret = 0;
        while (bfs())
            for (int u=1; u<=n; u++)
                if (!matchL[u] && dfs(u))
                    ret++;
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> d1(n), d2(n);
        for (int &x : d1)
            cin >> x;
        for (int &x : d2)
            cin >> x;

        vector<array<int, 3>> v;
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++) {
                v.push_back({abs(d1[i] - d2[j]), i, j});
                v.push_back({d1[i] + d2[j], i, j});
            }
        sort(v.begin(), v.end());

        int cur = 0;
        vector<int> visL(n), visR(n);
        for (int ii=0; ii<(int)v.size(); ) {
            int jj = ii, d = v[ii][0];
            cur++;
            int left = 0, right = 0;
            while (jj < (int) v.size() && v[jj][0] == d) {
                int l = v[jj][1], r = v[jj][2];
                jj++;
                if (visL[l] != cur) {
                    visL[l] = cur;
                    left++;
                }
                if (visR[r] != cur) {
                    visR[r] = cur;
                    right++;
                }
            }
            if (left == n && right == n) {
                Matching matching(n, n);
                for (int k=ii; k<jj; k++)
                    matching.addEdge(v[k][1] + 1, v[k][2] + 1);
                if (matching.solve() == n) {
                    int p1 = 0, p2 = d;
                    vector<int> h(n);
                    for (int i=0; i<n; i++) {
                        int j = matching.matchL[i+1] - 1;
                        if (d2[j] - d1[i] == d)
                            h[i] = -d1[i];
                        else if (d1[i] - d2[j] == d)
                            h[i] = d + d2[j];
                        else
                            h[i] = d1[i];
                    }

                    int shift = min(*min_element(h.begin(), h.end()), 0);
                    p1 -= shift, p2 -= shift;
                    for (int &x : h)
                        x -= shift;

                    cout << "YES\n";
                    for (int x : h)
                        cout << x << " ";
                    cout << "\n" << p1 << " " << p2 << "\n";
                    goto done;
                }
            }
            ii = jj;
        }
        cout << "NO\n";
        done:;
    }

    return 0;
}