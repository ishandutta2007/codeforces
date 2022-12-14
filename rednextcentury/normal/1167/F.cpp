#include <bits/stdc++.h>
using namespace std;
#define mid (l+r)/2
#define L x*2
#define R (L+1)
long long tree[4000000][2];
long long mod=1000000007;
void upd(int x,int l,int r,int v,long long val,int id)
{
    if (v>r || v<l)return;
    if (l==r)tree[x][id]+=val,tree[x][id]%=mod;
    else
    {
        if (v<=mid)
            upd(L,l,mid,v,val,id);
        else
            upd(R,mid+1,r,v,val,id);
        tree[x][id]=(tree[L][id]+tree[R][id])%mod;
    }
}
long long query(int x,int l,int r,int s,int e,int id)
{
    if (l>e || r<s)return 0;
    if (l>=s && r<=e)return tree[x][id];
    return (query(L,l,mid,s,e,id)+query(R,mid+1,r,s,e,id))%mod;
}
pair<long long,int> a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    long long ret=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
        ret+=(((a[i].first*i)%mod)*(n-i+1))%mod;
        ret%=mod;
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        int j = a[i].second;
        long long ansL = query(1,1,n,1,j,0);
        long long ansR = query(1,1,n,j,n,1);
        ret+=(((ansL*(n-j+1))%mod)*a[i].first)%mod;
        ret+=(((ansR*j)%mod)*a[i].first)%mod;
        ret%=mod;
        upd(1,1,n,j,j,0);
        upd(1,1,n,j,n-j+1,1);
    }
    cout<<ret<<endl;
}