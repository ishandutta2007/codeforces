#include<cstdio>
#include<vector>

#define N 100010

using namespace std;

struct lhy{
    int sum,lazy,r;
}tree[4*3*N];

int n,ans,L,R,l[N],r[N],v[N];
vector<pair<int,int> >v1[3*N],v2[3*N];

inline void down(int k)
{
    tree[k<<1].sum+=tree[k].lazy;
    tree[k<<1].lazy+=tree[k].lazy;
    tree[k<<1|1].sum+=tree[k].lazy;
    tree[k<<1|1].lazy+=tree[k].lazy;
    tree[k].lazy=0;
}

inline void up(int k)
{
    if(tree[k<<1].sum>tree[k<<1|1].sum)tree[k].sum=tree[k<<1].sum,tree[k].r=tree[k<<1].r;
    else tree[k].sum=tree[k<<1|1].sum,tree[k].r=tree[k<<1|1].r;
}

void add(int k,int l,int r,int ll,int rr,int o)
{
    if(ll<=l&&r<=rr)
    {
        tree[k].sum+=o;
        tree[k].lazy+=o;
        return;
    }
    down(k);
    int mid=(l+r)>>1;
    if(mid>=ll)add(k<<1,l,mid,ll,rr,o);
    if(mid<rr)add(k<<1|1,mid+1,r,ll,rr,o);
    up(k);
}

void pre(int k,int l,int r)
{
    if(l==r)
    {
        tree[k].r=r;
        return;
    }
    int mid=(l+r)>>1;
    pre(k<<1,l,mid);
    pre(k<<1|1,mid+1,r);
    tree[k].r=tree[k<<1|1].r;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&l[i],&v[i],&r[i]);
        v1[l[i]].push_back(make_pair(v[i],r[i]));
        v2[v[i]+1].push_back(make_pair(v[i],r[i]));
    }
    pre(1,1,3*N);
    for(int i=1;i<=300001;i++)
    {
        int o=v2[i].size();
        for(int j=0;j<(int)v1[i].size();j++)
            add(1,1,3*N,v1[i][j].first,v1[i][j].second,1);
        for(int j=0;j<(int)v2[i].size();j++)
            add(1,1,3*N,v2[i][j].first,v2[i][j].second,-1);
        if(tree[1].sum>ans)ans=tree[1].sum,L=i,R=tree[1].r;
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)
        if(l[i]<=L&&R<=r[i]&&L<=v[i]&&R>=v[i])printf("%d ",i);
}