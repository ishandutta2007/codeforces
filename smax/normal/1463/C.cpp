#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> t(n), x(n);
        for (int i=0; i<n; i++)
            cin >> t[i] >> x[i];

        int pos = 0, ti = 0, target = -2, ret = 0;
        for (int i=0; i<n; i++) {
            int diff = t[i] - ti;
            bool success = false;
            if (target != -2) {
                DEBUG(x[target])
                if (pos > x[target]) {
                    int old = pos;
                    int dist = min(pos - x[target], diff);
                    ti += dist;
                    pos -= dist;
                    DEBUG(i, pos, old, x[i-1])
                    if (i > 0 && pos <= x[i-1] && x[i-1] <= old)
                        success = true;
                    if (pos == x[target])
                        target = -2;
                } else {
                    int old = pos;
                    int dist = min(x[target] - pos, diff);
                    ti += dist;
                    pos += dist;
                    DEBUG(i, pos, old, x[i-1])
                    if (i > 0 && old <= x[i-1] && x[i-1] <= pos)
                        success = true;
                    if (pos == x[target])
                        target = -2;
                }
            }
            if (success)
                ret++, DEBUG(i, "SUCCESS");
            if (target == -2) {
                // can perform next operation
                ti = t[i];
                target = i;
            }
        }
        if (target != -2) {
            DEBUG(pos, target, x[target])
            if (pos > x[target]) {
                int old = pos;
                int dist = pos - x[target];
                ti += dist;
                pos -= dist;
                if (pos <= x[n-1] && x[n-1] <= old)
                    ret++, DEBUG(n, "SUCCESS");
                if (pos == x[target])
                    target = -2;
            } else {
                int old = pos;
                int dist = x[target] - pos;
                ti += dist;
                pos += dist;
                if (old <= x[n-1] && x[n-1] <= pos)
                    ret++, DEBUG(n, "SUCCESS");
                if (pos == x[target])
                    target = -2;
            }
        }
        cout << ret << "\n";
    }

    return 0;
}