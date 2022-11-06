#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=2e5+5, inf=1e18;

ll ara[sz], tree[sz*4], extra[sz*4];

typedef pair <ll,ll> pii;
#define x first
#define y second

pii a[sz], b[sz];
pair <pii,int> mt[sz];
ll big[sz];

void update(int node, int b, int e, int i, int j, ll v)
{
    if(e<i || j<b) return;
    if(i<=b && e<=j) {
        tree[node] += v;
        extra[node] += v;
        return;
    }

    int l=node<<1, r=l+1, m=(b+e)>>1;

    update(l, b, m, i, j, v);
    update(r, m+1, e, i, j, v);
    tree[node] = max(tree[l], tree[r]) + extra[node];
}

ll query(int node, int b, int e, int i, int j, ll carry = 0)
{
    if(e<i || j<b) return 0;
    if(i<=b && e<=j) {
        return tree[node] + carry;
    }
    carry+=extra[node];

    int l=node<<1, r=l+1, m=(b+e)>>1;

    return query(l, b, m, i, j, carry) + query(r, m+1, e, i, j, carry);
}

int main()
{
    int n,m,p;
    cin >> n >> m >> p;
    for(int i=1; i<=n; i++) scanf("%lld %lld", &a[i].x, &a[i].y);
    for(int i=1; i<=m; i++) scanf("%lld %lld", &b[i].x, &b[i].y);
    for(int i=1; i<=p; i++) scanf("%lld %lld %lld", &mt[i].x.x, &mt[i].x.y, &mt[i].y);

    sort(b+1,b+m+1);
    sort(mt+1,mt+p+1);
    for(int i=1; i<=m; i++) update(1, 1, m, i, i, -b[i].y);

    for(int i=1; i<=p; i++) {
        ll tk = mt[i].y;
        int er = upper_bound(b+1, b+m+1, make_pair(mt[i].x.y, inf)) - b;
        if(er <= m) update(1, 1, m, er, m, tk);
        big[i] = query(1, 1, m, 1, m);
    }

    ll ans = -inf;
    for(int i=1; i<=p; i++) ara[i] = mt[i].x.x;
    for(int i=1; i<=n; i++) {
        int ar = upper_bound(ara+1, ara+p+1, a[i].x-1) - ara - 1;
        if(ar) ans = max(ans, big[ar]-a[i].y);
    }

    if(ans == -inf) {
        ll za=inf, zb=inf;
        for(int i=1; i<=n; i++) za=min(za, a[i].y);
        for(int i=1; i<=m; i++) zb=min(zb, b[i].y);
        ans = 0-za-zb;
    }

    printf("%lld\n", ans);
}