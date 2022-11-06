#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e4+5;

int n,m,k,lim;
ll a[55][sz], dp[55][sz], ara[sz], tree[sz*4], extra[sz*4];

void form(int node, int b, int e)
{
    if(b==e) {
        tree[node]=ara[b];
        return;
    }

    int l=node<<1, r=l+1, m=(b+e)>>1;

    form(l, b, m);
    form(r, m+1, e);
    tree[node] = max(tree[l], tree[r]);
}

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

void add(int j, ll v)
{
    update(1, 1, m, max(j-k+1,1), min(j,lim), v);
}

void clean()
{
    memset(ara, 0, sizeof ara);
    memset(tree, 0, sizeof tree);
    memset(extra, 0, sizeof extra);
}

int main()
{
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%lld", &a[i][j]);
        }
    }

    lim=m-k+1;
    for(int i=n; i; i--) {
        clean();

        for(int j=1; j<=k; j++) ara[1] += a[i][j] + a[i+1][j];

        for(int j=2; j<=lim; j++) {
            ara[j] = ara[j-1];
            ara[j] += a[i][j+k-1] + a[i+1][j+k-1];
            ara[j] -= a[i][j-1] + a[i+1][j-1];
        }

        for(int j=1; j<=lim; j++) ara[j] += dp[i+1][j];

        form(1, 1, m);

        dp[i][0]=tree[1];

        for(int j=1; j<=k; j++) add(j, -a[i][j]);

        dp[i][1]=tree[1];

        for(int j=2; j<=lim; j++) {
            add(j-1, +a[i][j-1]);
            add(j+k-1, -a[i][j+k-1]);
            dp[i][j]=tree[1];
        }
    }

    cout << dp[1][0];
}