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
        vector<vector<int>> adj(n);
        for (int i=0; i<n-1; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int k1;
        cin >> k1;
        vector<int> x(k1);
        for (int i=0; i<k1; i++) {
            cin >> x[i];
            x[i]--;
        }
        int k2;
        cin >> k2;
        vector<int> y(k2);
        for (int i=0; i<k2; i++) {
            cin >> y[i];
            y[i]--;
        }

        vector<int> touch(n, -1);
        queue<int> q;
        for (int u : x) {
            touch[u] = u;
            q.push(u);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
                if (touch[v] == -1) {
                    touch[v] = touch[u];
                    q.push(v);
                }
        }

        cout << "B " << y[0] + 1 << endl;
        int ret;
        cin >> ret;
        assert(ret != -1);
        ret--;
        if (find(x.begin(), x.end(), ret) != x.end()) {
            cout << "C " << ret + 1 << endl;
            continue;
        }

        cout << "A " << touch[ret] + 1 << endl;
        int ret2;
        cin >> ret2;
        assert(ret2 != -1);
        ret2--;
        if (find(y.begin(), y.end(), ret2) != y.end())
            cout << "C " << touch[ret] + 1 << endl;
        else
            cout << "C -1" << endl;
    }

    return 0;
}