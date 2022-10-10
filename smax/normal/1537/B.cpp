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

    int t;
    cin >> t;
    while (t--) {
        int n, m, i, j;
        cin >> n >> m >> i >> j;
        array<long long, 5> best;
        best[0] = LLONG_MIN;
        for (long long x1 : {1, n})
            for (long long y1 : {1, m})
                for (long long x2 : {1, n})
                    for (long long y2 : {1, m})
                        best = max(best, {abs(i - x1) + abs(i - x2) + abs(x1 - x2) + abs(j - y1) + abs(j - y2) + abs(y1 - y2), x1, y1, x2, y2});
        cout << best[1] << " " << best[2] << " " << best[3] << " " << best[4] << "\n";
    }

    return 0;
}