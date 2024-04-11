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

    int n, m;
    cin >> n >> m;
    vector<vector<int>> in(n);
    vector<int> out(n);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (a > b)
            swap(a, b);
        in[a].push_back(b);
        out[b]++;
    }

    long long ret = 0;
    for (int u=0; u<n; u++)
        ret += (long long) in[u].size() * out[u];
    cout << ret << "\n";

    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        int u;
        cin >> u;
        u--;
        ret -= (long long) in[u].size() * out[u];
        for (int v : in[u]) {
            ret -= in[v].size();
            out[v]--;
            ret += out[v];
            out[u]++;
            in[v].push_back(u);
        }
        in[u].clear();
        cout << ret << "\n";
    }

    return 0;
}