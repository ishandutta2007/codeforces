#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

int a[sz], tree[sz*4], extra[sz*4];

void update(int node, int b, int e, int i, int j, int v = 1)
{
    if(j<b || e<i) return;
    if(i<=b && e<=j) {
        tree[node] += v*(e-b+1);
        extra[node] += v;
        return;
    }

    int l=node<<1, r=l+1, m=b+e>>1;

    update(l, b, m, i, j, v);
    update(r, m+1, e, i, j, v);
    tree[node] = tree[l] + tree[r] + (e-b+1)*extra[node];
}

int query(int node, int b, int e, int i, int j, int car = 0)
{
    if(i>j || e<i || j<b) return 0;
    if(i<=b && e<=j)
        return tree[node] + car*(e-b+1);

    car += extra[node];

    int l=node<<1, r=l+1, m=b+e>>1;

    return query(l, b, m, i, j, car) + query(r, m+1, e, i, j, car);
}

map <int,int> mp;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i=0; i<n; i++) scanf("%d", &a[i]);

        mp.clear();
        for(int i=0; i<k*8; i++) tree[i] = extra[i] = 0;

        for(int i=0; i<n/2; i++) {
            int j=n-1-i;
            int mx = k + max(a[i], a[j]);
            int mn = 1 + min(a[i], a[j]);
            mp[a[i] + a[j]]++;
            update(1, 1, 2*k, mn, mx);
        }

        int ans = n;
        for(int i=2; i<=k*2; i++) {
            int x = query(1, 1, 2*k, i, i);
            int now = n - x - mp[i];
//            printf("%d %d %d\n", n, x, mp[i]);
            ans = min(ans, now);
        }

        printf("%d\n", ans);
    }
}