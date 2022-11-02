#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MOD = 1e9 + 7;

int add(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        a += MOD;
    return a;
}

int mul(int a, int b) {
    return (ll) a * b % MOD;
}

int binpow(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            ans = mul(ans, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return ans;
}

const int MAXN = 1e5 + 10;
int n;
int a[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
}

int cnt[MAXN];
int dp[MAXN];

void calc() {
    for (int i = 1; i < MAXN; i++) {
        cnt[i] = 0;
        for (int x = 1; i * x < MAXN; x++) {
            cnt[i] += a[i * x];
        }
    }
    for (int gcd = MAXN - 1; gcd >= 2; gcd--) {
        dp[gcd] = add(dp[gcd], sub(binpow(2, cnt[gcd]), 1));
        for (int i = 2; i * gcd < MAXN; i++) {
            dp[gcd] = sub(dp[gcd], dp[i * gcd]);
        }
    }
}

int ans;

void make_ans() {
    ans = sub(binpow(2, n), 1);
    for (int i = 2; i < MAXN; i++) {
        ans = sub(ans, dp[i]);
    }
}

void run() {
    calc();
    make_ans();
}

void write() {
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}