#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MOD = 1e9 + 7;

int mul(int a, int b) {
    return (ll) a * b % MOD;
}

int binpow(int a, ll n) {
    int ans = 1;
    while (n) {
        if (n & 1LL) {
            ans = mul(ans, a);
        }
        a = mul(a, a);
        n >>= 1LL;
    }
    return ans;
}

ll n, m, k;

void read() {
    cin >> n >> m >> k;
    n--;
    m--;
}

int ans;

void run() {
    ans = binpow(binpow(2, n), m);
    if (((n + m) & 1) && k == -1) ans = 0;
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