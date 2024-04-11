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

#define MAXN 100005

int c[MAXN], id[MAXN], mx[MAXN];
long long tot[MAXN], ret[MAXN];
vector<int> adj[MAXN];
map<int, int> mp[MAXN];

void dfs(int u, int par) {
    mp[id[u]][c[u]] = 1;
    mx[id[u]] = 1;
    tot[id[u]] = c[u];
    for (int v : adj[u])
        if (v != par) {
            dfs(v, u);
            if (mp[id[v]].size() > mp[id[u]].size())
                swap(id[u], id[v]);
            for (auto &p : mp[id[v]]) {
                int &cur = mp[id[u]][p.first];
                cur += p.second;
                if (cur > mx[id[u]]) {
                    mx[id[u]] = cur;
                    tot[id[u]] = 0;
                }
                if (cur == mx[id[u]])
                    tot[id[u]] += p.first;
            }
        }
    ret[u] = tot[id[u]];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> c[i];
        id[i] = i;
    }
    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(0, -1);
    for (int i=0; i<n; i++)
        cout << ret[i] << " ";
    cout << "\n";

    return 0;
}