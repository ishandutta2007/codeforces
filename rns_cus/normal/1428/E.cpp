#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, k, a[N], b[N];

typedef long long ll;

inline ll calc(int a, int b) {
    int r = a % b;
    return (1ll * a * a - 1ll * r * r) / b + r;
}

inline ll del(int a, int b) {
    return calc(a, b) - calc(a, b + 1);
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), b[i] = 1;
    sort(a + 1, a + n + 1);
    typedef pair <ll, int> pii;
    priority_queue <pii> pq;
    ll ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans += calc(a[i], b[i]);
        pq.emplace(del(a[i], b[i]), i);
    }
    while (k -- > n) {
        pii p = pq.top(); pq.pop();
        ans -= p.first;
        int x = p.second;
        b[x] ++; pq.emplace(del(a[x], b[x]), x);
    }
    printf("%I64d\n", ans);

    return 0;
}