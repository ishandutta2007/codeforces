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

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<vector<int>> pos(n);
        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            a--;
            pos[a].push_back(i);
        }

        int uniq = 0;
        for (const auto &v : pos)
            if (!v.empty())
                uniq++;

        int last = n - 1;
        while (pos[last].empty())
            last--;
        int ret = uniq - 1, inc = 1;
        for (int i=last-1; i>=0; i--)
            if (!pos[i].empty()) {
                if (pos[i].back() < pos[last][0])
                    inc++;
                else
                    inc = 1;
                ret = min(ret, uniq - inc);
                last = i;
            }
        cout << ret << "\n";
    }

    return 0;
}