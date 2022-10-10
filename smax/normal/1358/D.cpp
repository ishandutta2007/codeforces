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

long long d[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    long long x;
    cin >> n >> x;
    for (int i=0; i<n; i++)
        cin >> d[i];

    long long ret = 0, tot = 0, memoX = x;

    // beginning of month
    for (int i=0, j=0; i<n; i++) {
        while (d[j] <= x) {
            tot += d[j] * (d[j] + 1) / 2;
            x -= d[j];
            if (++j == n)
                j = 0;
        }
        tot += x * (x + 1) / 2;
        ret = max(ret, tot);
        DEBUG(i, j, tot, x)
        tot -= (i != j ? d[i] * (d[i] + 1) / 2 : 0) + x * (x + 1) / 2;
        x += (i != j ? d[i] : 0);
        if (i == j)
            if (++j == n)
                j = 0;
    }

    // end of month
    tot = 0;
    x = memoX;
    for (int i=n-1, j=n-1; i>=0; i--) {
        while (d[j] <= x) {
            tot += d[j] * (d[j] + 1) / 2;
            x -= d[j];
            if (--j < 0)
                j = n - 1;
        }
        tot += d[j] * (d[j] + 1) / 2 - (d[j] - x) * (d[j] - x + 1) / 2;
        ret = max(ret, tot);
        DEBUG(i, j, tot, x)
        tot -= (i != j ? d[i] * (d[i] + 1) / 2 : 0) + d[j] * (d[j] + 1) / 2 - (d[j] - x) * (d[j] - x + 1) / 2;
        x += (i != j ? d[i] : 0);
        if (i == j)
            if (--j < 0)
                j = n - 1;
    }

    cout << ret << "\n";

    return 0;
}