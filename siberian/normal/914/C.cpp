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

int inv(int a) {
    return binpow(a, MOD - 2);
}

const int MAXN = 1010;
int fact[MAXN], rfact[MAXN];
int dp[MAXN];

void build() {
    fact[0] = rfact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = mul(fact[i - 1], i);
        rfact[i] = inv(fact[i]);
    }
    dp[1] = 0;
    dp[0] = -1e9;
    for (int i = 2; i < MAXN; i++) {
        dp[i] = dp[__builtin_popcount(i)] + 1;
    }
}

int cnk(int n, int k) {
    if (k < 0 || n < k) return 0;
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

string s;
int k;

void read() {
    cin >> s >> k;
    if (k == 0) {
        cout << 1 << endl;
        exit(0);
    }
    if (s == "1") {
        cout << (k == 0) << endl;
        exit(0);
    } 
}

int ans = 0;

void run() {   
    int cnt = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '0') continue;
        for (int Add = 0; Add <= (int) s.size(); Add++) {
            if (Add > (int)s.size() - i - 1) break;
            if (dp[cnt + Add] != k - 1) continue;
            if (cnt > 0 || Add > 1)
                ans = add(ans, cnk((int)s.size() - i - 1, Add));
            else
                ans = add(ans, cnk((int)s.size() - i - 2, Add));
        }
        cnt++; 
    }    
    if (dp[cnt] == k - 1) {
        ans = add(ans, 1);
    }
}

void write() {
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    build();
    read();
    run();
    write();
    return 0;
}