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
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> x(n);
        for (int i=0; i<n; i++)
            cin >> x[i];

        sort(x.begin(), x.end());
        long long g = 0;
        for (int i=1; i<n; i++)
            g = __gcd(g, x[i] - x[i-1]), DEBUG(i, x[i] - x[i-1]);

        bool ok = false;
        for (int i=0; i<n; i++)
            ok |= abs(x[i] - k) % g == 0, DEBUG(i, x[i] - k);
        cout << (ok ? "YES" : "NO") << "\n";

        // bool ok = false;
        // for (int i=0; i<n; i++)
        //     for (int j=i+1; j<n; j++) {
        //         long long d = abs(x[i] - x[j]);
        //         if (abs(x[j] - k) % d == 0) {
        //             DEBUG(i, j, k)
        //             ok = true;
        //         }
        //     }
        // cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}