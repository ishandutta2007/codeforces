#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

long long xi[100000], yi[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    long long x1, y1, x2, y2;
    int n;
    string s;
    cin >> x1 >> y1 >> x2 >> y2 >> n >> s;

    long long x = x1, y = y1;
    for (int i=0; i<n; i++) {
        if (s[i] == 'U') y++;
        else if (s[i] == 'D') y--;
        else if (s[i] == 'L') x--;
        else x++;
        xi[i] = x;
        yi[i] = y;
    }
    long long dx = x - x1, dy = y - y1;

    long long ret = LLONG_MAX;
    for (int i=0; i<n; i++) {
        long long l = 0, r = 1e9;
        while (l < r) {
            long long m = (l + r) / 2;
            if (abs(x2 - xi[i] - m * dx) + abs(y2 - yi[i] - m * dy) <= m * n + i + 1)
                r = m;
            else
                l = m + 1;
        }
        if (abs(x2 - xi[i] - l * dx) + abs(y2 - yi[i] - l * dy) <= l * n + i + 1)
            ret = min(ret, l * n + i + 1);
    }

    cout << (ret == LLONG_MAX ? -1 : ret) << "\n";

    return 0;
}