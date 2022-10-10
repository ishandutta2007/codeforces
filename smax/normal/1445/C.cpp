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

    int t;
    cin >> t;
    while (t--) {
        long long p, q;
        cin >> p >> q;
        long long mn = LLONG_MAX, cpy = p;
        for (int i=2; i*i<=q; i++) {
            if (q % i == 0) {
                long long pow1 = 1;
                while (q % i == 0) {
                    pow1 *= i;
                    q /= i;
                }
                long long pow2 = 1;
                while (p % i == 0) {
                    pow2 *= i;
                    p /= i;
                }
                mn = min(mn, pow2 >= pow1 ? pow2 / pow1 * i : 1);
            }
        }
        if (q > 1) {
            long long pow2 = 1;
            while (p % q == 0) {
                pow2 *= q;
                p /= q;
            }
            mn = min(mn, pow2);
        }
        cout << cpy / mn << "\n";
    }

    return 0;
}