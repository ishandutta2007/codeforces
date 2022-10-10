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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int r = -1;
        vector<int> b(n);
        vector<vector<int>> adj(n);
        for (int i=0; i<n; i++) {
            cin >> b[i];
            b[i]--;
            if (b[i] == i)
                r = i;
            else
                adj[b[i]].push_back(i);
        }
        vector<int> p(n);
        for (int i=0; i<n; i++) {
            cin >> p[i];
            p[i]--;
        }

        set<int> st{r};
        bool ok = true;
        vector<int> ret(n), dist(n);
        int last = -1;
        for (int u : p) {
            if (!st.count(u)) {
                ok = false;
                break;
            }
            st.erase(u);
            ret[u] = last + 1 - dist[b[u]];
            dist[u] = last + 1;
            last++;
            for (int v : adj[u])
                if (v != b[u])
                    st.insert(v);
        }

        if (ok) {
            for (int w : ret)
                cout << w << " ";
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}