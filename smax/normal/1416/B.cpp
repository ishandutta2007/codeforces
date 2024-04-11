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
        cin >> n;
        vector<int> a(n);
        int tot = 0;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            tot += a[i];
        }
        if (tot % n) {
            cout << "-1\n";
            continue;
        }

        cout << 3 * (n - 1) << "\n";
        for (int i=1; i<n; i++) {
            int rem = (i + 1 - a[i] % (i + 1)) % (i + 1);
            cout << "1 " << i + 1 << " " << rem << "\n" << i + 1 << " 1 " << (a[i] + rem) / (i + 1) << "\n";
        }
        for (int i=1; i<n; i++)
            cout << "1 " << i + 1 << " " << tot / n << "\n";
    }

    return 0;
}