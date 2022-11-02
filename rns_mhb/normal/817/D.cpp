#include <bits/stdc++.h>
using namespace std;

#define N 1000005

typedef long long ll;
const int inf = 1e9;
int n;
int a[N], l[N], r[N];
ll ans;

ll calc() {
    for (int i = 1; i <= n; i ++) {
        l[i] = i - 1;
        while (a[l[i]] <= a[i]) l[i] = l[l[i]];
    }
    for (int i = n; i >= 1; i --) {
        r[i] = i + 1;
        while (a[r[i]] < a[i]) r[i] = r[r[i]];
    }
    ll rtn = 0;
    for (int i = 1; i <= n; i ++) {
        rtn += 1ll * (i - l[i]) * (r[i] - i) * a[i];
    }
    return rtn;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
    }
    a[0] = a[n+1] = inf;
    ans = calc();
    for (int i = 1; i <= n; i ++) {
        a[i] = -a[i];
    }
    ans += calc();
    printf("%I64d\n", ans);
    return 0;
}