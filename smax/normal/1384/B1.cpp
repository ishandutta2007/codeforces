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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++;
else if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k, l;
        cin >> n >> k >> l;
        vector<int> d(n);
        for (int i=0; i<n; i++) {
            cin >> d[i];
            d[i] += k;  // offset it so that you first decrease for k seconds, then increase for k seconds
        }

        int lo = 0, hi = 2 * k;
        bool ok = true;
        for (int i=0; i<n; i++) {
            if (d[i] - l > k) {
                ok = false;
                break;
            }
            int nlo = max(d[i] - l, 0), nhi = (int) min(l + 2LL * k - d[i], 2LL * k);
            if (nlo > 0) {
                if (max(lo, nlo - 1) > min(hi, nhi - 1)) {
                    ok = false;
                    break;
                }
                lo = max(lo, nlo - 1) + 1;
                hi = nhi;
            } else {
                assert(nhi == 2 * k);
                lo = nlo;
                hi = nhi;
            }
        }
        cout << (ok ? "Yes" : "No") << "\n";
    }

    return 0;
}