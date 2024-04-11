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

const int INF = 2e8 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), t(n);
        for (int &x : a)
            cin >> x;
        for (int &x : t)
            cin >> x;

        auto check = [&] (double m) -> pair<double, bool> {
            double lo = -INF, hi = INF;
            for (int i=0; i<n; i++) {
                lo = max(lo, a[i] - (m - t[i]));
                hi = min(hi, a[i] + (m - t[i]));
            }
            return {lo, lo <= hi};
        };

        double l = *max_element(t.begin(), t.end()), r = INF;
        for (int rep=0; rep<200; rep++) {
            double m = (l + r) / 2;
            if (check(m).second)
                r = m;
            else
                l = m;
        }
        cout << fixed << setprecision(10) << check(l).first << "\n";
    }

    return 0;
}