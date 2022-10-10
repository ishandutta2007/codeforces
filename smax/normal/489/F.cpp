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

int n, mod, cnt[505], dp[505][505];

void add(int &a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}

int mul(int a, int b) {
    return (long long) a * b % mod;
}

int solve(int row, int one, int two) {
    if (row == n)
        return one == 0 && two == 0;
    if (dp[one][two] != -1)
        return dp[one][two];

    dp[one][two] = 0;
    if (one > 1)
        add(dp[one][two], mul(solve(row + 1, one - 2, two), one * (one - 1) / 2));
    if (one > 0 && two > 0)
        add(dp[one][two], mul(solve(row + 1, one, two - 1), one * two));
    if (two > 1)
        add(dp[one][two], mul(solve(row + 1, one + 2, two - 2), two * (two - 1) / 2));

    return dp[one][two];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int m;
    cin >> n >> m >> mod;
    for (int i=0; i<m; i++) {
        string s;
        cin >> s;
        for (int j=0; j<n; j++)
            cnt[j] += (s[j] == '1');
    }

    int one = 0, two = 0;
    for (int j=0; j<n; j++) {
        if (cnt[j] == 0)
            two++;
        else if (cnt[j] == 1)
            one++;
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(m, one, two) << "\n";

    return 0;
}