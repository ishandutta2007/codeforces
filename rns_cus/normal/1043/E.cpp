#include <bits/stdc++.h>
using namespace std;

#define N 300300

typedef long long ll;
typedef pair <int, int> pii;
int n, m, x[N], y[N], id[N];
ll ans[N], sum[N];

int main() {
    scanf("%d %d", &n, &m);
    vector <pii> vec;
    ll tot = 0, sum = 0;
    for (int i = 0; i < n; i ++) scanf("%d %d", &x[i], &y[i]), vec.emplace_back(y[i] - x[i], i), tot += x[i];
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i ++) {
        int a, b;
        tie(a, b) = vec[i];
        ans[b] = tot + 1ll * (n - 2) * x[b] + sum + 1ll * a * (n - 1 - i);
        sum += a;
    }
    while (m --) {
        int u, v;
        scanf("%d %d", &u, &v); u --, v --;
        int p = min(x[u] + y[v], x[v] + y[u]);
        ans[u] -= p, ans[v] -= p;
    }
    for (int i = 0; i < n; i ++) printf("%lld ", ans[i]);

}