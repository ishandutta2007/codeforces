#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 1e6 + 10;
const int MOD = 998244353;

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

int n;
vector<int> g[MAXN];
int cnt[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int sz;
        cin >> sz;
        while (sz--) {
            int a;
            cin >> a;
            g[i].push_back(a);
            cnt[a]++;
        }
    }
}

int ans;

void run() {
    ans = 0;
    for (int i = 0; i < n; i++) {
        for (auto x : g[i]) {
            int fadd = cnt[x];
            fadd = mul(fadd, inv(n));
            fadd = mul(fadd, inv(g[i].size()));
            ans = add(ans, fadd);
        }
    }
    ans = mul(ans, inv(n));
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