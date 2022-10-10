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

int maxDegree = 0, node = -1, beef = -1;
bool leaf[100000];
vector<int> adj[100000];

bool dfs(int u, int p, int d) {
    if (adj[u].size() > maxDegree) {
        maxDegree = adj[u].size();
        node = u;
    }
    bool isLeaf = true, ret = false;
    for (int v : adj[u])
        if (v != p) {
            isLeaf = false;
            ret |= dfs(v, u, d + 1);
        }
    if (p == -1 && (adj[u].size() <= 1))
        leaf[u] = true;
    if (isLeaf) {
        leaf[u] = true;
//        if (d > diameter) {
//            diameter = d;
//            farthest = u;
//        }
        beef = u;
        return d % 2 == 1;
    }
    return ret;
}

int dfsMax(int u, int p) {
    bool hasOne = false;
    int ret = 0;
    for (int v : adj[u])
        if (v != p) {
            int res = dfsMax(v, u);
            if (res == 0) {
                if (!hasOne) {
                    hasOne = true;
                    ret += res + 1;
                }
            } else {
                ret += res + 1;
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
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1, 0);
    bool hasOdd = dfs(beef, -1, 0);
    int gg = dfsMax(node, -1);
    cout << min((hasOdd ? 3 : 1), gg) << " " << gg << "\n";

//    for (int i=0; i<n; i++) {
//        if (leaf[i])
//            continue;
//        assert(dfsMax(i, -1) <= gg);
//    }

    return 0;
}