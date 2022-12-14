#include <bits/stdc++.h>
using namespace std;
#define mid (l+r)/2
#define L x*2
#define R x*2+1
int tree[4000000];
int lazy[4000000];
int mxx=0;
void lzy(int x,int l,int r)
{
    tree[x]+=lazy[x];
    if (l!=r)
        lazy[L]+=lazy[x],lazy[R]+=lazy[x];
    lazy[x]=0;
}
void rangeUpd(int x,int l,int r,int s,int e,int val)
{
    lzy(x,l,r);
    if (s>r || e<l)
        return;
    if (l>=s && r<=e)
    {
        lazy[x]+=val;
        lzy(x,l,r);
        return;
    }
    rangeUpd(L,l,mid,s,e,val);
    rangeUpd(R,mid+1,r,s,e,val);
    tree[x]=min(tree[x*2],tree[x*2+1]);
}
int getFirstZero(int x,int l,int r)
{
    lzy(x,l,r);
    if (tree[x]!=0)
        return -1;
    if (l==r)
        return l;
    lzy(L,l,mid);lzy(R,mid+1,r);
    if (tree[L]==0)
        return getFirstZero(L,l,mid);
    else
        return getFirstZero(R,mid+1,r);
}
vector<pair<int,int> > adj[1000000];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)adj[i].clear();
        for (int i=0;i<=5*n;i++)
            tree[i]=0,lazy[i]=0;
        mxx=0;
        for (int i=1;i<=n;i++)
        {
            int nxt;
            scanf("%d",&nxt);
            if (nxt==-1)continue;
            if (nxt!=n+1)
                adj[nxt].push_back({i,i}),rangeUpd(1,1,n,i,i,1);
            if (i+1<nxt)
                adj[i].push_back({i+1,nxt-1}),rangeUpd(1,1,n,i+1,nxt-1,1);

        }
        vector<int> ret(n+1);
        bool ok=1;
        for (int i=n;i>=1;i--)
        {
            int v = getFirstZero(1,1,n);
            if (v==-1)
            {
                ok=0;
                break;
            }
            ret[v]=i;
            rangeUpd(1,1,n,v,v,1e9);
            for (auto p:adj[v])
                rangeUpd(1,1,n,p.first,p.second,-1);
        }
        if (!ok)printf("-1\n");
        else
        {
            for (int i = 1; i <= n; i++)
                printf("%d ", ret[i]);
            printf("\n");
        }
    }
}