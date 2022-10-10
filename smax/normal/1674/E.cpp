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

    // any pair
    int mn1 = INT_MAX, mn2 = INT_MAX;
    for (int x : a) {
        x = (x + 1) / 2;
        if (x < mn1) {
            mn2 = mn1;
            mn1 = x;
        } else if (x < mn2) {
            mn2 = x;
        }
    }
    int ret = mn1 + mn2;

    // adjacent pair
    for (int i=1; i<n; i++)
        ret = min(ret, max({(a[i-1] + 1) / 2, (a[i] + 1) / 2, (a[i-1] + a[i] + 2) / 3}));

    // two apart
    for (int i=2; i<n; i++)
        ret = min(ret, min(a[i-2], a[i]) + (max(a[i-2], a[i]) - min(a[i-2], a[i]) + 1) / 2);

    cout << ret << "\n";

    return 0;
}