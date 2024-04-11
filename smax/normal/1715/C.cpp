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

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    long long ret = 0;
    for (int i=1; i<=n; i++)
        ret += (long long) i * (n - i + 1);
    for (int i=1; i<n; i++)
        if (a[i-1] == a[i])
            ret -= (long long) i * (n - i);

    for (int i=0; i<m; i++) {
        int p, x;
        cin >> p >> x;
        p--;

        if (p > 0 && a[p-1] == a[p])
            ret += (long long) p * (n - p);
        if (p + 1 < n && a[p] == a[p+1])
            ret += (long long) (p + 1) * (n - p - 1);

        a[p] = x;

        if (p > 0 && a[p-1] == a[p])
            ret -= (long long) p * (n - p);
        if (p + 1 < n && a[p] == a[p+1])
            ret -= (long long) (p + 1) * (n - p - 1);

        cout << ret << "\n";
    }

    return 0;
}