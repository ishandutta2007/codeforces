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

const int MAX = 1e6;

double solve(int c, int m, int p, int v) {
    double ret = 1;
    if (c > 0) {
        if (m > 0)
            ret += (double) c / MAX * solve(c - min(c, v), m + min(c, v) / 2, p + min(c, v) / 2, v);
        else
            ret += (double) c / MAX * solve(c - min(c, v), 0, p + min(c, v), v);
    }
    if (m > 0) {
        if (c > 0)
            ret += (double) m / MAX * solve(c + min(m, v) / 2, m - min(m, v), p + min(m, v) / 2, v);
        else
            ret += (double) m / MAX * solve(0, m - min(m, v), p + min(m, v), v);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    cout << fixed << setprecision(10);
    while (t--) {
        double dc, dm, dp, dv;
        cin >> dc >> dm >> dp >> dv;
        int c = round(dc * MAX), m = round(dm * MAX), p = round(dp * MAX), v = round(dv * MAX);
        cout << solve(c, m, p, v) << "\n";
    }

    return 0;
}