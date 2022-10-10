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

int k, has[10][10];
bool ban[10][10][10][10], ban2[10][10];
vector<int> cur;
vector<pair<int, int>> adj[200005], pairs[200005];

int solve(int i) {
    if (i == k + 1)
        return 1;
    int ret = 0;
    for (int j=0; j<i; j++)
        if (!ban2[i][j]) {
            bool ok = true;
            for (int l=1; l<i; l++)
                ok &= !ban[i][j][l][cur[l-1]];
            if (ok) {
                cur.push_back(j);
                ret += solve(i + 1);
                cur.pop_back();
            }
        }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m >> k;
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
    }

    for (int i=0; i<n; i++) {
        sort(adj[i].begin(), adj[i].end(), [] (const pair<int, int> &a, const pair<int, int> &b) {
            return a.second < b.second;
        });
        for (int j=0; j<adj[i].size(); j++)
            pairs[adj[i][j].first].emplace_back(adj[i].size(), j);
    }
    for (int i=0; i<n; i++) {
        for (auto &p : pairs[i]) {
            if (has[p.first][p.second] == i + 1) ban2[p.first][p.second] = true;
            else has[p.first][p.second] = i + 1;
        }
        for (int a=1; a<=k; a++)
            for (int b=0; b<a; b++)
                if (has[a][b] == i + 1)
                    for (int c=1; c<=k; c++)
                        for (int d=0; d<c; d++)
                            if (has[c][d] == i + 1)
                                ban[a][b][c][d] = ban[c][d][a][b] = true;
    }

    cout << solve(1) << "\n";

    return 0;
}