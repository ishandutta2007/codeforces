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

    cout << "? " << 2 * n + 2 << "\n";
    cout << n << " " << m + 1 << "\n";
    cout << 0 << " " << m + 1 << "\n";
    for (int i=0; i<n; i++) {
        cout << i << " " << 0 << "\n";
        cout << i + 1 << " " << m << "\n";
    }
    cout.flush();

    double s;
    cin >> s;
    double y = m * s - 0.5;

    cout << "? " << 2 * m + 2 << "\n";
    cout << n + 1 << " " << 0 << "\n";
    cout << n + 1 << " " << m << "\n";
    for (int i=0; i<m; i++) {
        cout << 0 << " " << m - i << "\n";
        cout << n << " " << m - i - 1 << "\n";
    }
    cout.flush();

    cin >> s;
    double x = n * s - 0.5;

    cout << "! " << x << " " << y << endl;

    return 0;
}