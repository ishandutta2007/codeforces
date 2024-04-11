#include <bits/stdc++.h>
using namespace std;

#define N 200020

typedef long long ll;

int m, n;
ll a[N], b[N];

void get_a(ll sum, ll &x, ll &y, ll mn, ll mx) {
    x = mn, y = sum - x;
    if (y > mx) y = mx, x = sum - mx;
    assert(x >= mn && y <= mx);
}

int main() {
    scanf("%d", &n);
    m = n / 2;
    for (int i = 1; i <= m; i ++) scanf("%I64d", &b[i]);
    ll mn = 0, mx = 1e18;
    for (int i = 1; i <= m; i ++) {
        get_a(b[i], a[i], a[n+1-i], mn, mx);
        mn = a[i], mx = a[n+1-i];
    }
    for (int i = 1; i <= n; i ++) printf("%I64d ", a[i]);
}