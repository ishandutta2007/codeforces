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

int ask(int i) {
    cout << "? " << i + 1 << endl;
    int ret;
    cin >> ret;
    assert(ret != 0);
    return ret - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<bool> vis(n);
        vector<int> p(n);
        for (int i=0; i<n; i++)
            if (!vis[i]) {
                int x = ask(i);
                vector<int> cycle{x};
                while (true) {
                    int y = ask(i);
                    if (x == y)
                        break;
                    cycle.push_back(y);
                }
                rotate(cycle.begin(), find(cycle.begin(), cycle.end(), i), cycle.end());
                for (int j=0; j<(int)cycle.size(); j++) {
                    vis[cycle[j]] = true;
                    p[cycle[j]] = cycle[(j+1)%cycle.size()];
                }
            }

        cout << "!";
        for (int x : p)
            cout << " " << x + 1;
        cout << endl;
    }

    return 0;
}