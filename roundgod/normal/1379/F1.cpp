#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q,a[MAXN],b[MAXN];
set<int> L[MAXN],R[MAXN];
struct segtree
{
    int maxi[4*MAXN],mini[4*MAXN];
    bool flag[4*MAXN];
    void pushup(int k)
    {
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
        mini[k]=min(mini[k*2],mini[k*2+1]);
        flag[k]=flag[k*2]||flag[k*2+1]||(maxi[k*2+1]>=mini[k*2]);
    }
    void build(int k,int l,int r)
    {
        if(l==r)
        {
            maxi[k]=-INF; mini[k]=INF;
            flag[k]=(maxi[k]>=mini[k]?true:false);
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int p,int id,int v)
    {
        if(l==r)
        {
            if(id==0) maxi[k]=v; else mini[k]=v;
            flag[k]=(maxi[k]>=mini[k]?true:false);
            return;
        }
        int mid=(l+r)/2;
        if(p<=mid) update(k*2,l,mid,p,id,v); else update(k*2+1,mid+1,r,p,id,v);
        pushup(k);
    }
}seg;
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    seg.build(1,1,n);
    for(int i=0;i<q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x&1)
        {
            if(!L[(x+1)/2].count(y))
            {
                L[(x+1)/2].insert(y);
                int mini=(L[(x+1)/2].size()?*L[(x+1)/2].begin():INF);
                seg.update(1,1,n,(x+1)/2,1,mini);
            }
            else
            {
                L[(x+1)/2].erase(y);
                int mini=(L[(x+1)/2].size()?*L[(x+1)/2].begin():INF);
                seg.update(1,1,n,(x+1)/2,1,mini);
            }
        }
        else
        {
            if(!R[(x+1)/2].count(y))
            {
                R[(x+1)/2].insert(y);
                int maxi=(R[(x+1)/2].size()?*(--R[(x+1)/2].end()):-INF);
                seg.update(1,1,n,(x+1)/2,0,maxi);
            }
            else
            {
                R[(x+1)/2].erase(y);
                int maxi=(R[(x+1)/2].size()?*(--R[(x+1)/2].end()):-INF);
                seg.update(1,1,n,(x+1)/2,0,maxi);
            }
        }
        if(seg.flag[1]) puts("NO"); else puts("YES");
    }
    return 0;
}