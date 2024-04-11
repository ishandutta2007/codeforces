#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
    int x = 0, f = 1; char c = getchar();
    while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
    while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
    return x * f;
}

const int N = 1e5 + 5;
int n, k, a[N], b[N], sum[N], ans[N], mx[N], mn[N];

int GetSum(int l, int r) { return sum[r] - sum[l - 1]; }

main() {
    n = get(), k = get();
    for(int i = 1; i <= n; i++) a[i] = get();
    for(int i = 1; i <= n; i++) b[i] = get();
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    mn[n + 1] = a[n];
    for(int i = n; i >= 1; i--) ans[i] = max(ans[i + 1], GetSum(i, n) - b[i]), mn[i] = min(mn[i + 1], a[i]);
    if(k == 0) return printf("%lld\n", ans[1]), 0;
    mx[1] = b[1];
    for(int i = 2; i <= n; i++) mx[i] = min(mx[i - 1], b[i]);
    int res = (k > 1)? ans[1] : 0;
    for(int i = 2; i <= n; i++) res = max(res, ans[i]);
    for(int i = 1; i < n; i++) res = max(res, GetSum(1, i) - mx[i] + ans[i + 1]);
    if(k >= 2) res = max(res, sum[n] - mx[n - 1]);
    for(int i = 1; i < n - 1; i++) res = max(res, GetSum(i, n) - mn[i + 1] - b[i]);
    printf("%lld\n", res);
    return 0;
}