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

template<int SZ>
struct DSU {
    int parent[SZ], Size[SZ];

    void init(int n) {
        for (int i=0; i<n; i++) {
            parent[i] = i;
            Size[i] = 1;
        }
    }

    int Find(int u) {
        if (u != parent[u])
            parent[u] = Find(parent[u]);
        return parent[u];
    }

    void Union(int u, int v) {
        u = Find(u);
        v = Find(v);
        if (u != v) {
            if (Size[u] < Size[v])
                swap(u, v);
            parent[v] = u;
            Size[u] += Size[v];
        }
    }
};

DSU<26> ds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    string a, b;
    cin >> n >> a >> b;

    ds.init(26);
    vector<pair<char, char>> ret;
    for (int i=0; i<n; i++)
        if (ds.Find(a[i] - 'a') != ds.Find(b[i] - 'a')) {
            ds.Union(a[i] - 'a', b[i] - 'a');
            ret.emplace_back(a[i], b[i]);
        }

    cout << ret.size() << "\n";
    for (auto p : ret)
        cout << p.first << " " << p.second << "\n";

    return 0;
}