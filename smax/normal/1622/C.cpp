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
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

long long floorDiv(long long a, long long b) {
    return a / b - (a < 0 && a % b != 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());
        long long tot = accumulate(a.begin(), a.end(), 0LL), ret = max(tot - k, 0LL);
        tot -= a[0];
        for (int i=n-1; i>0; i--) {
            // change first to some x, then set suffix equal to x
            tot -= a[i];
            long long x = floorDiv(k - tot, n - i + 1);
            long long ntot = tot + (n - i) * x + min(x, (long long) a[0]);
            ret = min(ret, max(ntot - k, 0LL) + n - i + max(a[0] - x, 0LL));
        }
        cout << ret << "\n";
    }

    return 0;
}