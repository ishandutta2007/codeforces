#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 1e5 + 5;

int n;
long long a[MAXN];
long long b[MAXN], sum[MAXN];

long long solve(long long len) {
    int idx = upper_bound(b + 1, b + n, len) - 1 - b;
    
    return sum[idx] + (n - idx) * len;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a + i);
    }
    
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; ++i) {
        b[i] = a[i + 1] - a[i];
    }
    sort(b + 1, b + n);
    for (int i = 1; i < n; ++i) {
        sum[i] = sum[i - 1] + b[i];
    }
    
    int q; scanf("%d", &q);
    while (q--) {
        long long l, r;
        scanf("%lld%lld", &l, &r);
        
        printf("%lld\n", solve(r - l + 1));
    }
    
    return 0;
}