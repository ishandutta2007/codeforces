#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long lazy[1000001];
long long tree[1000001];
set<long long> s;
long long a[1000001];
long long b[1000001];
void build(int x,int l,int r)
{
    if (l==r)
    {
        if (l%2)tree[x]=a[l];
        else tree[x]=-a[l];
    }
    else
    {
        build(x*2,l,(l+r)/2);
        build(x*2+1,(l+r)/2+1,r);
        tree[x]=tree[x*2]+tree[x*2+1];
    }
}
void lzy(int x,int l,int r)
{
    if ((r-l+1)%2)
    {
        if (l%2)tree[x]+=lazy[x];
        else tree[x]-=lazy[x];
    }
    lazy[x*2]+=lazy[x];
    lazy[x*2+1]+=lazy[x];
    lazy[x]=0;
}
void upd(int x,int l,int r,int s,int e,long long add)
{
    lzy(x,l,r);
    if (l>e || s>r)
        return;
    if (l>=s && r<=e)
    {
        lazy[x]+=add;
        lzy(x,l,r);
        return;
    }
    upd(x*2,l,(l+r)/2,s,e,add);
    upd(x*2+1,(l+r)/2+1,r,s,e,add);
    tree[x]=tree[x*2]+tree[x*2+1];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=m;i++)
    {
        cin>>b[i];
        if (i%2==0)b[i]=-b[i];
        b[i]=b[i]+b[i-1];
    }
    for (int i=n;i<=m;i++)
    {
        long long sum = b[i]-b[i-n];
        int l = i-n+1;
        if (l%2==0)sum=-sum;
        s.insert(sum);
    }
    build(1,1,n);
    {
    long long sum = tree[1];
        long long best=1e18;
        set<long long>::iterator it = s.upper_bound(sum);
        if (it!=s.end())
        {
            best = min(best,abs(sum-*it));
        }
        if (it!=s.begin())
        {
            it--;best = min(best,abs(sum-*it));

        }
        cout<<best<<endl;
    }
    while(q--)
    {
        int l,r,add;
        cin>>l>>r>>add;
        upd(1,1,n,l,r,add);
        lzy(1,1,n);
        long long sum = tree[1];
        long long best=1e18;
        set<long long>::iterator it = s.upper_bound(sum);
        if (it!=s.end())
        {
            best = min(best,abs(sum-*it));
        }
        if (it!=s.begin())
        {
            it--;best = min(best,abs(sum-*it));

        }
        cout<<best<<endl;
    }
}