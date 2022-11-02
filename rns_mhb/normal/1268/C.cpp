#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> order_set;

order_set S;

#define N 200010

typedef long long ll;

ll g[N];
int a[N], f[N];

void addf(int x) {
    for(; x < N; x += x & -x) f[x] ++;
}

void addg(int x, int v) {
    for(; x < N; x += x & -x) g[x] += v;
}

int queryf(int x) {
    int ret = 0;
    for(; x; x &= x - 1) ret += f[x];
    return ret;
}

ll queryg(int x) {
    ll ret = 0;
    for(; x; x &= x - 1) ret += g[x];
    return ret;
}

int p[N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), p[a[i]] = i;
    ll inv = 0;
    order_set s;
    for(int i = 1; i <= n; i ++) {
        inv += queryf(n) - queryf(p[i]);
        addf(p[i]);
        addg(p[i], p[i]);
        s.insert(p[i]);
        if(i & 1) {
            int m = i+1>>1;
            int mp = *s.find_by_order(m-1);
            ll ans = inv + queryg(n) - queryg(mp) - queryg(mp-1) - 1ll * (i-1>>1) * (i+1>>1);
            printf("%I64d ", ans);
        }
        else {
            int m = i>>1;
            int mp = *s.find_by_order(m-1);
            ll ans = inv + queryg(n) - 2*queryg(mp) - 1ll * (i>>1) * (i>>1);
            printf("%I64d ", ans);
        }
    }
    puts("");
}