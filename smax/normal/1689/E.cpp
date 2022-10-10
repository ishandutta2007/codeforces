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

const int LOG = 30;

struct DSU {
    vector<int> par, sz;

    DSU(int n) : par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }

    int find(int u) {
        return u == par[u] ? u : par[u] = find(par[u]);
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (sz[u] < sz[v])
            swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

int solve(vector<int> a, bool print = false) {
    int n = (int) a.size();
    DSU dsu(n + LOG);
    for (int i=0; i<n; i++)
        for (int j=0; j<LOG; j++)
            if (a[i] >> j & 1)
                dsu.unite(i, n + j);
    vector<int> rep(n + LOG, -1);
    set<int> st;
    for (int i=0; i<n; i++) {
        int u = dsu.find(i);
        if (rep[u] == -1 || a[i] & 1)
            rep[u] = i;
        st.insert(u);
    }
    int ret = 0;
    if (st.size() > 1)
        for (int i : rep)
            if (i != -1 && ~a[i] & 1) {
                ret++;
                a[i]++;
            }
    if (print) {
        for (int x : a)
            cout << x << " ";
        cout << "\n";
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a)
            cin >> x;

        int ret1 = solve(a), ret2 = INT_MAX, cand = -1;
        for (int i=0; i<n; i++)
            if (a[i] > 0) {
                vector<int> b = a;
                b[i]--;
                int cur = solve(b) + 1;
                if (cur < ret2) {
                    ret2 = cur;
                    cand = i;
                }
            }

        if (ret1 < ret2) {
            cout << ret1 << "\n";
            solve(a, true);
        } else {
            a[cand]--;
            cout << ret2 << "\n";
            solve(a, true);
        }
    }

    return 0;
}