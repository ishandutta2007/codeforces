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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        long long pow4 = 1;
        bool infinity = false;
        for (int i=0; i<n; i++) {
            pow4 *= 4;
            if (k <= (pow4 - 1) / 3) {
                if (i < n - 1)
                    infinity = true;
                break;
            }
        }
        if (k > (pow4 - 1) / 3) {
            cout << "NO\n";
            continue;
        }

        int i;
        long long pow2 = 2, add = 0;
        for (i=1; i<=n; i++) {
            pow2 *= 2;
            pow4 /= 4;
            if (k < pow2 - i - 2) {
                i--;
                pow2 /= 2;
                break;
            }
            if ((pow4 - 1) / 3 > k / (pow2 - 3))
                infinity = true;
            add += (pow2 - 3) * (pow4 - 1) / 3;
            if (infinity || k <= pow2 - i - 2 + add)
                break;
        }

        if (!infinity && k > pow2 - i - 2 + add)
            cout << "NO\n";
        else
            cout << "YES " << n - i << "\n";
    }

    return 0;
}