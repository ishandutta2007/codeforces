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
        long long x, y, a, b;
        cin >> x >> y >> a >> b;
        if (a > b) {
            swap(a, b);
            swap(x, y);
        }

        if (a == b) {
            cout << min(x, y) / a << "\n";
            continue;
        }

        auto solve = [&] (long long n) -> long long {
            long long leftX = x - n * a, leftY = y - n * b;
            return n + min(leftX / b, leftY / a);
        };

        // N uses a red, b blue
        // M uses b red, a blue
        // Na + Mb <= x
        // Nb + Ma <= y
        // intersection point: N = (yb - xa) / (b^2 - a^2)
        long long ret = 0;
        for (long long d=-2; d<=2; d++) {
            long long n = (y * b - x * a) / (b * b - a * a) + d;
            n = max(n, 0LL);
            n = min({n, x / a, y / b});
            ret = max(ret, solve(n));
        }
        cout << ret << "\n";
    }

    return 0;
}