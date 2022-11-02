#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> order_set;
typedef long long ll;

#define N 200005

int n, k;

struct station{
    int x, r, f;
    station(int x = 0, int r = 0, int f = 0) : x(x), r(r), f(f) {}
    bool operator< (const station &b) const {
        return r > b.r;
    }
} a[N];

order_set s[N/10+5];
ll ans;

int main() {
    
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i ++) {
        scanf("%d %d %d", &a[i].x, &a[i].r, &a[i].f);
    }
    sort(a, a + n);
    for (int i = 0; i < n; i ++) {
        for (int j = max(1, a[i].f - k); j <= a[i].f + k; j ++) {
            ans += s[j].order_of_key(a[i].x + a[i].r + 1) - s[j].order_of_key(a[i].x - a[i].r);
        }
        s[a[i].f].insert(a[i].x);
    }
    printf("%I64d\n", ans);
    return 0;
}