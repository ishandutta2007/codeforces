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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++;
else if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(n);
        for (int i=0; i<n; i++)
            cin >> a[i];
        for (int i=0; i<n; i++)
            cin >> b[i];

        vector<int> has(n + 1, -1);
        vector<vector<int>> need(n + 1);
        for (int i=0; i<n; i++) {
            has[b[i]] = i;
            if (a[i] != b[i])
                need[b[i]].push_back(i);
        }
        DEBUG(has, need);

        int waste = 0;
        vector<int> ret;
        for (int i=0; i<m; i++) {
            int c;
            cin >> c;
            if (!need[c].empty()) {
                waste++;
                while (waste--)
                    ret.push_back(need[c].back());
                need[c].pop_back();
                waste = 0;
            } else if (has[c] != -1) {
                waste++;
                while (waste--)
                    ret.push_back(has[c]);
                waste = 0;
            } else {
                waste++;
            }
        }

        bool ok = true;
        for (int i=1; i<=n; i++)
            ok &= need[i].empty();
        if (ok && waste == 0) {
            cout << "YES\n";
            for (int x : ret)
                cout << x + 1 << " ";
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}