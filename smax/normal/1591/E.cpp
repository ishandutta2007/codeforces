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

using ordered_set = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        vector<vector<int>> adj(n);
        vector<vector<array<int, 3>>> queries(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
            a[i]--;
        }
        for (int i=1; i<n; i++) {
            int p;
            cin >> p;
            p--;
            adj[p].push_back(i);
        }
        for (int i=0; i<q; i++) {
            int v, l, k;
            cin >> v >> l >> k;
            v--, k--;
            queries[v].push_back({l, k, i});
        }

        vector<int> cnt(n), ret(q);
        ordered_set st;

        auto dfs = [&] (auto &self, int u) -> void {
            if (cnt[a[u]] > 0)
                st.erase({cnt[a[u]], a[u]});
            cnt[a[u]]++;
            st.insert({cnt[a[u]], a[u]});
            for (auto [l, k, i] : queries[u]) {
                auto it = st.lower_bound({l, 0});
                int idx = k + (int) (it == st.end() ? st.size() : st.order_of_key(*it));
                DEBUG(idx, st, l, k, i, u);
                if (idx < (int) st.size())
                    ret[i] = st.find_by_order(idx)->second + 1;
                else
                    ret[i] = -1;
            }
            for (int v : adj[u])
                self(self, v);
            st.erase({cnt[a[u]], a[u]});
            cnt[a[u]]--;
            if (cnt[a[u]] > 0)
                st.insert({cnt[a[u]], a[u]});
        };

        dfs(dfs, 0);
        for (int x : ret)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}