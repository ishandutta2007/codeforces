//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vint = vector<int>;
using matr = vector<vint>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1e6 + 13;
const int M = 1e9 + 7;
const ld eps = 1e-6;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

matr sum(matr a, matr b) {
    matr c(a.size(), vint(a[0].size(), 0));
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[i].size(); j++)
            c[i][j] = sum(a[i][j], b[i][j]);
    }
    return c;
}

matr mul(matr a, matr b) {
    matr c(a.size(), vint(b[0].size(), 0));
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b[0].size(); j++) {
            for(int k = 0; k < a[0].size(); k++) {
                c[i][j] = sum(c[i][j], mul(a[i][k], b[k][j]));
            }
        }
    }
    return c;
}

matr pow2(matr a, li k) {
    if(k == 0) {
        matr c(a.size(), vint(a.size(), 0));
        for(int i = 0; i < a.size(); i++)
            c[i][i] = 1;
        return c;
    }

    matr pw = pow2(a, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, a));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    li k;
    cin >> n >> k;

    vector<li> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    matr dp(1, vint(n, 1));

    matr b(n, vint(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            b[i][j] = (__builtin_popcountll(a[i] ^ a[j]) % 3 == 0);
        }
    }

    dp = mul(dp, pow2(b, k - 1));

    int ans = 0;
    for(auto x : dp[0])
        ans = sum(ans, x);

    cout << ans << endl;
}