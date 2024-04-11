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

string s;
int n;

void read() {
    cin >> s >> n;    
}

// 2 ^ len + 2 ^ (len + |s|) + 2 ^ (len + 2 * |s|) + ...
// 1 + 2 ^ x + 2 ^ 2x + 2 ^ 3x + 2 ^ 4x = 2 ^ x * (2 ^ n - 1)


int ans;

void run() {
    int have = 0;
    int q = binpow(2, s.size());
    have = mul(sub(binpow(q, n), 1), inv(sub(q, 1)));
    ans = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if ((s[i] - '0') % 5) continue;
        ans = add(ans, mul(have, binpow(2, i)));
    }
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