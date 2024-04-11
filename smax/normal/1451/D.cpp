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
        long long d, k;
        cin >> d >> k;
        long long l = 0, r = d * d + 1;
        while (l < r) {
            long long m = (l + r) / 2;
            // check if there exists a point (x, y) such that x + y = m * k, x^2 + y^2 <= d^2
            __int128 x = m / 2 * k, y = (m - m / 2) * k;
            if (x * x + y * y <= d * d)
                l = m + 1;
            else
                r = m;
        }
        cout << ((l - 1) % 2 ? "Ashish" : "Utkarsh") << "\n";
    }

    return 0;
}