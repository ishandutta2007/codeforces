#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

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

const int MAXN = 1e6 + 10;
int pows[MAXN];

void build() {
    pows[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pows[i] = mul(pows[i - 1], 2);
    }
}

int n;
int a[MAXN];

void read() {
    cin >> n;
    cin >> a[1];
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        a[i] = add(a[i], a[i - 1]);
    }  
}

int ans;

void run() {
    build();
    ans = 0;
    for (int len = 1; len <= n; len++) {
        int cnt = 0;
        if (n == len) {
            cnt = 1;
        } else {
            cnt = add(cnt, pows[n - len]);
            //cout << len << " " << cnt << endl;
            cnt = add(cnt, mul(n - len - 1, pows[n - len - 2]));
        }
        //cout << len << " " << cnt << endl;
        ans = add(ans, mul(cnt, a[len]));
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