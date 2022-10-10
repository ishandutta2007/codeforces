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

int a[500005];
bool dp[500005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, d;
    cin >> n >> k >> d;
    for (int i=1; i<=n; i++)
        cin >> a[i];

    sort(a + 1, a + n + 1);
    dp[0] = true;
    int jSum = 0, kSum = 0;
    for (int i=1, j=0; i<=n; i++) {
        jSum += dp[i-1];
        while (j + 1 < i && a[i] - a[j+1] > d)
            jSum -= dp[j++];
        kSum += dp[i-1];
        if (i - k >= 0)
            kSum -= dp[i-k];
        dp[i] = (jSum - kSum > 0);
    }
    cout << (dp[n] ? "YES" : "NO") << "\n";

    return 0;
}