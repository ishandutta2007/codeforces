#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T, size_t N> ostream& operator << (ostream &os, const array<T, N> &a) {os << "("; for (int i=0; i<(int)N; i++) {if (i) os << ", "; os << a[i];} return os << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

int ret[1000000];
vector<int> adj[1000000];

pair<int, int> dfs(int u, int p, vector<int> &d) {
    pair<int, int> mx(1, 0);
    for (int v : adj[u])
        if (v != p) {
            vector<int> child;
            auto mx2 = dfs(v, u, child);
            if (d.size() < child.size())
                swap(d, child);
            mx = max(mx, {mx2.first, mx2.second});
            for (int i=1; i<=child.size(); i++) {
                d[d.size()-i] += child[child.size()-i];
                mx = max(mx, {d[d.size()-i], d.size() - i});
            }
        }
    d.push_back(1);
    mx = max(mx, {1, d.size() - 1});
    ret[u] = d.size() - mx.second - 1;
    return mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }

    vector<int> dummy;
    dfs(0, -1, dummy);

    for (int i=0; i<n; i++)
        cout << ret[i] << "\n";

    return 0;
}