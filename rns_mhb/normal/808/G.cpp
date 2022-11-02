#include <bits/stdc++.h>
using namespace std;

#define N 100005

template <class T> bool chkmax(T &a, T b) { return a < b ? a = b, 1 : 0; }
int n, m;
char s[N], t[N];
bool vis[N];
int dp[N], dp1[N];

int main() {
    scanf("%s %s", s, t);
    n = strlen(s), m = strlen(t);
    if (n < m) return puts("0"), 0;
    for (int i = 0; i < m; i ++) {
        vis[i] = 1;
        for (int j = 0; j <= i && vis[i]; j ++) if (t[j] != t[m-1-i+j]) vis[i] = 0;
    }
    for (int i = m - 1; i < n; i ++) {
        dp1[i] = dp1[i-1];
        bool flag = 0;
        for (int j = 0; j < m && !flag; j ++) {
            if (s[i-j] != '?' && s[i-j] != t[m-1-j]) flag = 1;
        }
        if (flag) continue;
        for (int j = 0; j <= m - 2; j ++) {
            if (vis[j]) chkmax(dp[i], dp[i-m+1+j] + 1);
        }
        chkmax(dp[i], (i != m - 1 ? dp1[i-m] : 0) + 1);
        chkmax(dp1[i], dp[i]);
    }
    printf("%d\n", dp1[n-1]);
    return 0;
}