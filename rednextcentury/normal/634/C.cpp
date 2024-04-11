#include<bits/stdc++.h>
using namespace std;
long long tree[1000000][2];
long long ar[1000000];
int a,b;
#define mid (l+r)/2
long long query(int x,int l,int r,int s,int e,bool k)
{
    if (l>e || r<s || s>e)
        return 0;
    if (l>=s && r<=e)
        return tree[x][k];
    else
    {
        return query(x*2,l,mid,s,e,k)+query(x*2+1,mid+1,r,s,e,k);
    }
}
void upd(int x,int l,int r,int v)
{
    if (v>r || v<l)return;
    if (l==r && v==l)
    {
        tree[x][0]=min(ar[v],b+0LL);
        tree[x][1]=min(ar[v],a+0LL);
    }
    else
    {
        upd(x*2,l,mid,v);
        upd(x*2+1,mid+1,r,v);
        tree[x][0]=tree[x*2][0]+tree[x*2+1][0];
        tree[x][1]=tree[x*2][1]+tree[x*2+1][1];
    }
}
int main()
{
    int n,k,q;
    cin>>n>>k>>a>>b>>q;
    while(q--)
    {
        int typ;
        scanf("%d",&typ);
        if (typ==1)
        {
            int d,x;
            scanf("%d%d",&d,&x);
            ar[d]+=x;
            upd(1,1,n,d);
        }
        else
        {
            int p;
            scanf("%d",&p);
            printf("%I64d\n",query(1,1,n,1,p-1,0)+query(1,1,n,p+k,n,1));
        }
    }
}