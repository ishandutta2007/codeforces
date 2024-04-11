#include <bits/stdc++.h>
using namespace std;
long long tree[2000000];
long long lazy[2000000];
long long a[1000000];
long long orig[1000000];
void build(int x,int l,int r)
{
    if (l==r)
        tree[x]=a[l];
    else
    {
        build(x*2,l,(l+r)/2);
        build(x*2+1,(l+r)/2+1,r);
        tree[x]=max(tree[x*2],tree[x*2+1]);
    }
}
void lzy(int x)
{
    tree[x]-=lazy[x];
    lazy[x*2]+=lazy[x];
    lazy[x*2+1]+=lazy[x];
    lazy[x]=0;
}
void upd1(int x,int l,int r,int s,int e,long long val)
{
    if (s>e)return;
    lzy(x);
    if (s>r || e<l)return;
    if (l>=s && r<=e)
    {
        lazy[x]+=val;
        lzy(x);
    }
    else
    {
        upd1(x*2,l,(l+r)/2,s,e,val);
        upd1(x*2+1,(l+r)/2+1,r,s,e,val);
        tree[x]=max(tree[x*2],tree[x*2+1]);
    }
}
void upd2(int x,int l,int r,int v)
{
    lzy(x);
    if (v<l || v>r)return;
    if (l==r)
    {
        lazy[x]=0;
        tree[x]=-1;
    }
    else
    {
        upd2(x*2,l,(l+r)/2,v);
        upd2(x*2+1,(l+r)/2+1,r,v);
        tree[x]=max(tree[x*2],tree[x*2+1]);
    }
}
pair<long long,int> query(int x,int l,int r,long long T)
{
    lzy(x);
    if (l==r)
    {
        if (tree[x]>T)return {tree[x],l};
        return {tree[1],-1};
    }
    lzy(x*2);
    lzy(x*2+1);
    if (tree[x*2]>T)
        return query(x*2,l,(l+r)/2,T);
    else return query(x*2+1,(l+r)/2+1,r,T);

}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    long long T=0;
    cin>>n>>T;
    for (int i=1;i<=n;i++)
        cin>>a[i],orig[i]=a[i],a[i]+=a[i-1];
    build(1,1,n);
    long long num=n;
    long long ret=0;
    while(1)
    {
        pair<long long,int> p = query(1,1,n,T);
        if (p.first<0)break;
        if (p.second==-1)
        {
            ret+=num*(T/p.first);
            T=T%p.first;
        }
        else
        {
            num--;
            upd1(1,1,n,p.second,n,orig[p.second]);
            upd2(1,1,n,p.second);
        }
    }
    cout<<ret<<endl;
}