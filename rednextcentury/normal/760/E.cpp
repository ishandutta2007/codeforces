# include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define L x*2
#define R L+1
#define mid (l+r)/2
int tree[1000000];
int balance[1000000];
int op[1000000];
int id[1000000],val[1000000];
int lazy[1000000];
multiset<pair<int,int> > all,cur;
void lzy(int x)
{
    lazy[L]+=lazy[x];
    lazy[R]+=lazy[x];
    tree[x]+=lazy[x];
    lazy[x]=0;
}
void upd(int x,int l,int r,int s,int e,int v)
{
    lzy(x);
    if (l>e || r<s)return;
    if (l>=s && r<=e)
    {
        lazy[x]+=v;
        lzy(x);
        return;
    }
    upd(L,l,mid,s,e,v);
    upd(R,mid+1,r,s,e,v);
    tree[x]=max(tree[x*2],tree[x*2+1]);
}
int getMaxBalance(int x,int l,int r,int s,int e)
{
    lzy(x);
    if (s>e)return 0;
    if (s>r || e<l)return -10000000;
    if (l>=s && r<=e)return tree[x];
    return max(getMaxBalance(L,l,mid,s,e),getMaxBalance(R,mid+1,r,s,e));
}
int a[1000000];
int ret[1000000];
int n;
void update(int i)
{
    i=id[i];
    if (a[i]==-1)
        upd(1,1,n,1,i,-1);
    else
        upd(1,1,n,1,i,1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x=-1;
        int typ;
        cin>>id[i]>>typ;
        if (typ==1)cin>>x;
        op[id[i]]=x;
        val[i]=x;
        a[id[i]]=x;
    }
    for (int i=1;i<=n;i++)
    {
        update(i);
        int ans=-1;
        int l=1,r=n;
        while(l<=r)
        {
            int Mid=(l+r)/2;
            if (getMaxBalance(1,1,n,Mid,n)>0)
                ans=Mid,l=Mid+1;
            else r=Mid-1;
        }
        if (ans==-1)
            ret[i]=-1;
        else
        {
            ret[i]=a[ans];
        }
    }
    for (int i=1;i<=n;i++)
        cout<<ret[i]<<endl;;
}