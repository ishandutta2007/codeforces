#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

int ti = 0, num[100001], low[100001], fr[300000];
pair<int, int> edges[300000];
vector<pair<int, int>> adj[100001];

void dfs(int u, int p) {
    num[u] = low[u] = ti++;
    for (auto e : adj[u]) {
        if (num[e.first] == -1) {
            fr[e.second] = u;
            dfs(e.first, u);
            low[u] = min(low[u], low[e.first]);
            if (num[u] < low[e.first]) {
                cout << "0\n";
                exit(0);
            }
        } else {
            fr[e.second] = e.first;
            if (e.first != p)
                low[u] = min(low[u], num[e.first]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> edges[i].first >> edges[i].second;
        adj[edges[i].first].emplace_back(edges[i].second, i);
        adj[edges[i].second].emplace_back(edges[i].first, i);
    }

    memset(num, -1, sizeof(num));
    dfs(1, -1);

    for (int i=0; i<m; i++)
        cout << fr[i] << " " << (fr[i] == edges[i].first ? edges[i].second : edges[i].first) << "\n";

    return 0;
}