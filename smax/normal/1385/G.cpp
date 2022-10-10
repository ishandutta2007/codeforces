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

#define MAXN 200005

int a[2][MAXN], color[MAXN];
vector<int> adj[MAXN], which[2];

void dfs(int u, int c = 0) {
    if (color[u] != -1) {
        assert(color[u] == c);
        return;
    }
    color[u] = c;
    which[c].push_back(u);
    for (int i=0; i<2; i++)
        for (int v : adj[a[i][u]])
            if (v != u) {
                if (a[i][u] == a[i][v])
                    dfs(v, 1 - c);
                else
                    dfs(v, c);
            }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(color, -1, sizeof(int) * n);
        for (int i=0; i<n; i++)
            adj[i].clear();
        for (int i=0; i<2; i++)
            for (int j=0; j<n; j++) {
                cin >> a[i][j];
                adj[--a[i][j]].push_back(j);
            }

        bool ok = true;
        for (int i=0; i<n; i++)
            if (adj[i].size() != 2) {
                ok = false;
                break;
            }
        if (!ok) {
            cout << "-1\n";
            continue;
        }

        vector<int> ret;
        for (int j=0; j<n; j++) {
            if (color[j] != -1 || a[0][j] == a[1][j])
                continue;
            for (int i=0; i<2; i++)
                which[i].clear();
            dfs(j);
            if (which[0].size() < which[1].size())
                ret.insert(ret.end(), which[0].begin(), which[0].end());
            else
                ret.insert(ret.end(), which[1].begin(), which[1].end());
        }

        cout << ret.size() << "\n";
        for (int x : ret)
            cout << x + 1 << " ";
        cout << "\n";
    }

    return 0;
}