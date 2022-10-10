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
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    if (n == 1) {
        cout << "0\n";
        return 0;
    }

    int ret = INT_MAX;
    for (int dx=-1; dx<=1; dx++)
        for (int dy=-1; dy<=1; dy++) {
            vector<int> b = a;
            b[0] += dx;
            b[1] += dy;
            int d = b[1] - b[0], cur = abs(dx) + abs(dy);
            bool ok = true;
            for (int i=2; i<n; i++) {
                int x = b[i-1] + d;
                if (abs(x - b[i]) > 1) {
                    ok = false;
                    break;
                }
                cur += abs(x - b[i]);
                b[i] = x;
            }
            DEBUG(d, ok, b);
            if (ok)
                ret = min(ret, cur);
        }
    cout << (ret == INT_MAX ? -1 : ret) << "\n";

    return 0;
}