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

const long double EPS = 1e-16;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long h, c, T;
        cin >> h >> c >> T;
        long double avg = (long double) (h + c) / 2, od = abs(h - T);
        if (T >= h) cout << "1\n";
        else if (T <= avg) cout << "2\n";
        else if (T > avg) {
            long long x = (T - h) / (c + h - 2 * T);
            long double val = (long double) (x * c + (x + 1) * h) / (2 * x + 1);
            long double diff = abs(T - val);
            while (true) {
                long long x2 = x + 1;
                long double val2 = (long double) (x2 * c + (x2 + 1) * h) / (2 * x2 + 1), diff2 = abs(T - val2);
                if (diff2 - diff > EPS || abs(diff2 - diff) <= EPS)
                    break;
                diff = diff2;
                x = x2;
            }
            if (diff < od) cout << 2 * x + 1 << "\n";
            else cout << "1\n";
        }
    }

    return 0;
}