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
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(1 << n);
        for (int i=0; i<n*(1<<(n-1)); i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> p(1 << n);
        vector<bool> used(1 << n);
        used[0] = true;
        int pw = 1;
        for (int v : adj[0]) {
            p[pw] = v;
            used[v] = true;
            pw *= 2;
        }
        for (int u=1; u<1<<n; u++)
            if (!p[u]) {
                set<int> st;
                for (int i=0; i<n; i++)
                    if ((u ^ (1 << i)) < u) {
                        if (st.empty()) {
                            for (int v : adj[p[u^(1<<i)]])
                                if (!used[v])
                                    st.insert(v);
                        } else {
                            set<int> st2;
                            for (int v : adj[p[u^(1<<i)]])
                                if (!used[v] && st.count(v))
                                    st2.insert(v);
                            st.swap(st2);
                        }
                    }
                assert(st.size() == 1);
                p[u] = *st.begin();
                used[*st.begin()] = true;
            }
        for (int x : p)
            cout << x << " ";
        cout << "\n";

        if ((n & (n - 1)) != 0) {
            cout << "-1\n";
            continue;
        }

        vector<int> ret(1 << n);
        for (int u=0; u<1<<n; u++) {
            int color = 0;
            for (int i=0; i<n; i++)
                if (u & (1 << i))
                    color ^= i;
            ret[p[u]] = color;
        }
        for (int x : ret)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}