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

int pref[40001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int a, b, q;
        cin >> a >> b >> q;

        int d = a * b / __gcd(a, b);
        for (int i=0; i<d; i++)
            pref[i] = (i > 0 ? pref[i-1] : 0) + (i % a % b != i % b % a);

        while (q--) {
            long long l, r;
            cin >> l >> r;

            cout << pref[d-1] * (r / d) + pref[r % d] - pref[d-1] * ((l - 1) / d) - pref[(l - 1) % d] << " ";
        }
        cout << "\n";
    }

    return 0;
}