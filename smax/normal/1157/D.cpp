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

int a[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    int memoN = n;

    for (int i=0; i<k; i++) {
        int l = (i > 0 ? a[i-1] + 1 : 1), r = (i > 0 ? 2 * a[i-1] + 1 : n + 1);
        while (l < r) {
            int m = (l + r) / 2;
            if ((long long) m * (k - i) + (long long) (k - i) * (k - i - 1) / 2 <= n)
                l = m + 1;
            else
                r = m;
        }
        a[i] = l - 1;
        n -= l - 1;
    }

    if (accumulate(a, a + k, 0) != memoN) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (int i=0; i<k; i++)
        cout << a[i] << " \n"[i==k-1];

    return 0;
}