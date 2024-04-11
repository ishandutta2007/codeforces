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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
struct BIT {
    int n, lg;
    vector<T> bit;

    BIT(int _n) : n(_n), lg(__lg(n)), bit(n + 1) {}

    BIT(const vector<T> &a) : n((int) a.size()), lg(__lg(n)), bit(n + 1) {
        for (int i=1; i<=n; i++) {
            bit[i] += a[i-1];
            if (i + (i & -i) <= n)
                bit[i+(i&-i)] += bit[i];
        }
    }

    T query(int i) {
        T ret = 0;
        for (i++; i>0; i-=i&-i)
            ret += bit[i];
        return ret;
    }

    T query(int l, int r) {
        return l > r ? 0 : query(r) - query(l - 1);
    }

    void update(int i, T val) {
        for (i++; i<=n; i+=i&-i)
            bit[i] += val;
    }

    int kth(T k) {
        int ret = 0;
        for (int i=lg; i>=0; i--) {
            ret += 1 << i;
            if (ret <= n && bit[ret] < k)
                k -= bit[ret];
            else
                ret -= 1 << i;
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    string s;
    cin >> n >> q >> s;

    vector<int> stk, rbs, deg(n), paired(n);
    vector<vector<int>> adj(n);
    for (int i=0; i<n; i++) {
        if (s[i] == '(') {
            stk.push_back(i);
        } else if (!stk.empty()) {
            paired[i] = stk.back();
            while (!rbs.empty() && rbs.back() > stk.back()) {
                adj[stk.back()].push_back(rbs.back());
                deg[stk.back()]++;
                rbs.pop_back();
            }
            rbs.push_back(stk.back());
            stk.pop_back();
        }
    }

    int ti = 0;
    vector<int> in(n), out(n), par(n, -1), depth(n);
    vector<ordered_set<int>> st(n);

    auto dfs = [&] (auto &self, int u) -> void {
        in[u] = ti++;
        st[depth[u]].insert(u);
        reverse(adj[u].begin(), adj[u].end());
        for (int v : adj[u]) {
            par[v] = u;
            depth[v] = depth[u] + 1;
            self(self, v);
        }
        out[u] = ti;
    };

    for (int u : rbs)
        dfs(dfs, u);
    BIT<long long> bit(n);
    for (int i=0; i<n; i++)
        bit.update(in[i], (long long) deg[i] * (deg[i] + 1) / 2);

    for (int i=0; i<q; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        l--, r--;
        if (t == 1) {
            bit.update(in[l], (long long) -deg[l] * (deg[l] + 1) / 2);
            st[depth[l]].erase(l);
            if (par[l] != -1)
                bit.update(in[par[l]], -deg[par[l]]--);
        } else {
            long long cnt = st[depth[l]].order_of_key(r) - st[depth[l]].order_of_key(l);
            cout << bit.query(in[l], out[paired[r]] - 1) + cnt * (cnt + 1) / 2 << "\n";
        }
    }

    return 0;
}