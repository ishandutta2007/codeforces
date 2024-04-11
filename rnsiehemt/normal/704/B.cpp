#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 5005;
const ll inf = 1e16;

int n, s, e;
ll x[maxn], a[maxn], b[maxn], c[maxn], d[maxn];
ll dp[2][maxn];

int main() {
    scanf("%d%d%d", &n, &s, &e); s--; e--;
    for (int i = 0; i < n; i++) scanf("%lld", x+i);
    for (int i = 0; i < n; i++) scanf("%lld", a+i);
    for (int i = 0; i < n; i++) scanf("%lld", b+i);
    for (int i = 0; i < n; i++) scanf("%lld", c+i);
    for (int i = 0; i < n; i++) scanf("%lld", d+i);

    std::fill(dp[0], dp[0]+maxn, inf);
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        std::fill(dp[1], dp[1]+maxn, inf);
        int ins = 0;
        if (i-1 >= s && i-1 < e) ins++;
        if (i-1 >= e && i-1 < s) ins--;
        if (i != s && i != e) {
            for (int j = 0; j < maxn; j++) {
                if (j >= 1) domin(dp[1][j], dp[0][j] + b[i] + c[i] + x[i] - x[i]);
                if (j+ins >= 1 && j >= 1) {
                    assert(j-1 >= 0);
                    domin(dp[1][j-1], dp[0][j] + a[i] + c[i] + x[i] + x[i]);
                }
                if (j+1 < maxn) domin(dp[1][j+1], dp[0][j] + b[i] + d[i] - x[i] - x[i]);
                if (j+ins >= 1) domin(dp[1][j], dp[0][j] + a[i] + d[i] + x[i] - x[i]);
            }
        }
        if (i == s) {
            for (int j = 0; j < maxn; j++) {
                if (j >= 1) domin(dp[1][j-1], dp[0][j] + c[i] + x[i]);
                domin(dp[1][j], dp[0][j] + d[i] - x[i]);
            }
        }
        if (i == e) {
            for (int j = 0; j < maxn; j++) {
                if (j+ins >= 1) domin(dp[1][j], dp[0][j] + a[i] + x[i]);
                if (j+1 < maxn) domin(dp[1][j+1], dp[0][j] + b[i] - x[i]);
            }
        }
        if (i < n-1) {
            if (!(i >= s && i < e)) dp[1][0] = inf;
        }
        for (int j = 0; j < maxn; j++) dp[0][j] = dp[1][j];
    }
    printf("%lld\n", dp[0][0]);
}