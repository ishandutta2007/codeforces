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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> color(n);
    set<int> st;
    for (int i=1; i<=n; i++)
        st.insert(i);

    auto dfs = [&] (auto &self, int u, int p) -> void {
        st.erase(color[u]);
        if (p != -1)
            st.erase(color[p]);
        for (int v : adj[u])
            if (v != p) {
                color[v] = *st.begin();
                st.erase(st.begin());
            }
        st.insert(color[u]);
        if (p != -1)
            st.insert(color[p]);
        for (int v : adj[u])
            if (v != p)
                st.insert(color[v]);
        for (int v : adj[u])
            if (v != p)
                self(self, v, u);
    };

    color[0] = 1;
    dfs(dfs, 0, -1);
    cout << set(color.begin(), color.end()).size() << "\n";
    for (int x : color)
        cout << x << " ";
    cout << "\n";

    return 0;
}