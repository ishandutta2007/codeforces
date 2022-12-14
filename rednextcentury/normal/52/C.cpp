#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000010
int tree[MAXN<<4];
int a[MAXN];
void build(int x,int l,int r)
{
    if (l==r)
    {
        tree[x]=tree[x]=a[l];
    }
    else
    {
        build(x<<1,l,(l+r)/2);
        build((x<<1)+1,(l+r)/2+1,r);
        tree[x]=min(tree[x*2],tree[x*2+1]);
    }
}
long long lazy[1000000];
void lzy(int x)
{
    tree[x]+=lazy[x];
    lazy[x*2]+=lazy[x],lazy[x*2+1]+=lazy[x];
    lazy[x]=0;
}
long long query(int x,int l,int r,int s,int e)
{
    lzy(x);
    if (s>r || e<l)
    {
        return 1000000000;
    }
    if (l>=s && r<=e)
        return tree[x];
    else
    {
        long long p1,p2;
        p1=query(x<<1,l,(l+r)/2,s,e);
        p2=query((x<<1)+1,(l+r)/2+1,r,s,e);
        return min(p1,p2);
    }
}
void upd(int x,int l,int r,int s,int e,int v)
{
    lzy(x);
    if (s>r || e<l)return;
    if (l>=s && r<=e)
    {
        lazy[x]+=v;
        lzy(x);
    }
    else
    {
        upd(x*2,l,(l+r)/2,s,e,v);
        upd(x*2+1,(l+r)/2+1,r,s,e,v);
        tree[x]=min(tree[x*2],tree[x*2+1]);
    }
}
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    build(1,0,n-1);
    int m;
    cin>>m;
    char inp[1000]="";
    for (int i=0;i<m;i++)
    {
        int l,r,v=1000000000;
        string x="";
        inp[0]='\0';
        while(strlen(inp)==0)
            gets(inp);
        x=inp;
        stringstream o_o(x);
        o_o>>l>>r>>v;
        if (v==1000000000)
        {
            if (l>r)
                printf("%I64d\n",min(query(1,0,n-1,l,n-1),query(1,0,n-1,0,r)));
            else
                printf("%I64d\n",query(1,0,n-1,l,r));
        }
        else
        {
            if (l<=r)
                upd(1,0,n-1,l,r,v);
            else
                upd(1,0,n-1,l,n-1,v),upd(1,0,n-1,0,r,v);
        }
    }
}