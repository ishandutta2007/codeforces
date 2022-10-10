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

// https://github.com/kth-competitive-programming/kactl/blob/main/content/graph/EulerWalk.h
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vi> eulerWalk(vector<vector<pii>>& gr, int nedges, int src=0) {
	int n = sz(gr);
	vi D(n), its(n), eu(nedges);
	// D[src]++; // to allow Euler paths, not just cycles
    vector<vector<int>> ret;
    vector<bool> vis(n);
    for (int i=0; i<n; i++) {
        if (!vis[i]) {
            ret.emplace_back();
            vector<int> s{i};
            while (!s.empty()) {
                int x = s.back(), y, e, &it = its[x], end = sz(gr[x]);
                vis[x] = true;
                if (it == end){ ret.back().push_back(x); s.pop_back(); continue; }
                tie(y, e) = gr[x][it++];
                if (!eu[e]) {
                    D[x]--, D[y]++;
                    eu[e] = 1; s.push_back(y);
                }}
        }
    }
	for (int x : D) if (x < 0) return {};
    for (int x : eu) if (x == 0) return {};
	return {ret.rbegin(), ret.rend()};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> m;
    vector<vector<int>> a(m);
    map<int, int> cnt;
    for (int i=0; i<m; i++) {
        int n;
        cin >> n;
        a[i].resize(n);
        for (int &x : a[i]) {
            cin >> x;
            cnt[x]++;
        }
    }

    int id = m;
    map<int, int> idx;
    for (const auto &p : cnt) {
        if (p.second % 2) {
            cout << "NO\n";
            return 0;
        }
        idx[p.first] = id++;
    }

    id = 0;
    vector<vector<pair<int, int>>> adj(m + cnt.size());
    for (int i=0; i<m; i++)
        for (int x : a[i]) {
            adj[i].emplace_back(idx[x], id);
            adj[idx[x]].emplace_back(i, id);
            id++;
        }

    vector<vector<int>> ret = eulerWalk(adj, id);
    if (ret.empty()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        vector<map<int, int>> mp(m);
        for (const auto &v : ret)
            for (int i=1; i<(int)v.size(); i++)
                if (v[i-1] < m)
                    mp[v[i-1]][v[i]]++;
        for (int i=0; i<m; i++) {
            for (int x : a[i])
                cout << (mp[i][idx[x]]-- > 0 ? 'L' : 'R');
            cout << "\n";
        }
    }

    return 0;
}