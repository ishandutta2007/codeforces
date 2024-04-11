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
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<n; i++)
        cin >> b[i];

    set<int> st;
    for (int i=0; i<n; i++)
        st.insert(i);

    vector<int> dist(n, -1);
    vector<pair<int, int>> par(n);
    queue<int> q;
    dist[n-1] = 0;
    q.push(n - 1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u < a[u]) {
            cout << dist[u] + 1 << "\n";
            vector<int> ret;
            ret.push_back(-1);
            while (u != n - 1) {
                ret.push_back(par[u].second);
                u = par[u].first;
            }
            reverse(ret.begin(), ret.end());
            for (int v : ret)
                cout << v + 1 << " ";
            cout << "\n";
            return 0;
        }
        auto it = st.upper_bound(u);
        while (it != st.begin() && *prev(it) >= u - a[u]) {
            it = prev(it);
            int v = *it;
            if (dist[v + b[v]] == -1) {
                dist[v + b[v]] = dist[u] + 1;
                par[v + b[v]] = {u, v};
                q.push(v + b[v]);
            }
            it = st.erase(it);
        }
    }
    cout << "-1\n";

    return 0;
}