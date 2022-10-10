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

const int MOD = 1e9 + 7;
const int INV = 500000004;

void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) a += MOD;
    return a;
}

int mul(int a, int b) {
    return (long long) a * b % MOD;
}

int a[5005], dp[5005][5005], up[10005], nup[10005], ret[10005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i=1; i<n; i++)
        cin >> a[i];

    dp[n][0] = 1;
    for (int i=n-1; i>0; i--) {
        dp[i][0] = 1;
        for (int j=0; j<n-i; j++)
            add(dp[i][j+1], mul(dp[i+1][j], a[i]));
    }

    int cnt = 1;
    for (int i=1; i<=n; i++) {
        memset(nup, 0, sizeof(nup));
        for (int j=1; j<=2*n-2; j++) {
            if (j <= n - i)
                add(ret[j], mul(dp[i][j], cnt));
            if (i > 1 && j <= n - i + 2)
                add(nup[j], sub(dp[i-1][j-1], j >= 2 ? dp[i][j-2] : 0));
            add(nup[j], up[j-1]);
            add(ret[j], mul(nup[j], cnt));
        }
        memcpy(up, nup, sizeof(up));
        cnt = mul(cnt, a[i]);
    }

    for (int i=1; i<=2*n-2; i++)
        cout << mul(ret[i], INV) << " ";
    cout << "\n";

    return 0;
}