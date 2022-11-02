#include <bits/stdc++.h>
using namespace std;

#define N 200100

typedef long long ll;

int n, m;
ll a[N], b[N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
    for (int i = 1; i <= m; i ++) scanf("%lld", &b[i]);
    sort(a + 1, a + n + 1);
    ll d = 0;
    for (int i = 2; i <= n; i ++) d = __gcd(d, a[i] - a[1]);
    for (int i = 1; i <= m; i ++) printf("%lld ", __gcd(d, a[1] + b[i]));

    return 0;
}