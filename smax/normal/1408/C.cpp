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
        int n, L;
        cin >> n >> L;
        vector<int> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];

        long double l = 0, r = 1e9;
        for (int rep=0; rep<200; rep++) {
            long double m = (l + r) / 2, lpos = 0, ti = m;
            for (int i=0; i<n; i++) {
                long double cur = min(ti, (a[i] - (i > 0 ? a[i-1] : 0)) / (long double) (i + 1));
                lpos += cur * (i + 1);
                ti -= cur;
            }
            long double fin = min(ti, (L - a[n-1]) / (long double) (n + 1));
            lpos += fin * (n + 1);
            long double rpos = L;
            ti = m;
            for (int i=n-1; i>=0; i--) {
                long double cur = min(ti, ((i < n - 1 ? a[i+1] : L) - a[i]) / (long double) (n - i));
                rpos -= cur * (n - i);
                ti -= cur;
            }
            fin = min(ti, a[0] / (long double) (n + 1));
            rpos -= fin * (n + 1);
            if (lpos < rpos)
                l = m;
            else
                r = m;
        }
        cout << fixed << setprecision(10) << l << "\n";
    }

    return 0;
}