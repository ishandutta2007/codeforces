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
    a -=b;
    if (a < 0)
        a += MOD;
    return a;
}

int mul(int a, int b) {
    return (ll) a * b % MOD;
}

const int MAXN = 110;

int pows[MAXN];

void build() {
    pows[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pows[i] = mul(2, pows[i - 1]);
    }
}

string s;
int n;

void read() {
    cin >> s;
    n = s.size();
}

int ans;

void run() {
    build();
    ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') continue;
        int L = pows[i];
        int R = pows[n - 1 - i];
        R = mul(R, R);
        ans = add(ans, mul(L, R));
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