#include<bits/stdc++.h>
#define MAXN 300005
#define MAXM 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,a[MAXN],b[MAXN];
vector<P> G[MAXM];
vector<int> from[MAXN];
int d[MAXN],dd[MAXN],to[MAXN];
bool deleted[MAXN];
int id[MAXN];
queue<int> que;
struct segtree
{
    vector<int> vec[MAXM];
    void build(int k,int l,int r)
    {
        if(l==r) {id[l]=k; return;}
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void update(int k,int l,int r,int x,int y,int v)
    {   
        if(l>y||x>r) return;
        if(l>=x&&r<=y)
        {
            vec[k].push_back(v);
            return;
        }
        int mid=(l+r)/2;
        update(k*2,l,mid,x,y,v); update(k*2+1,mid+1,r,x,y,v);
    }
}seg;
void notify(int x)
{
    int k=id[x];
    while(k>=1)
    {
        while(seg.vec[k].size())
        {
            int y=seg.vec[k].back();
            if(deleted[y])
            {
                seg.vec[k].pop_back();
                continue;
            }
            deleted[y]=true;
            d[y]=dd[x]+1;
            to[y]=x;
            que.push(y);
            seg.vec[k].pop_back(); 
        }
        k=k/2;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++) from[i+b[i]].push_back(i);
    for(int i=0;i<=n;i++) d[i]=dd[i]=INF;
    d[0]=dd[0]=0;
    memset(deleted,false,sizeof(deleted));
    seg.build(1,0,n);
    for(int i=1;i<=n;i++)
        seg.update(1,0,n,i-a[i],i,i);
    notify(0);
    while(que.size())
    {
        int x=que.front(); que.pop();
        for(auto y:from[x]) if(dd[y]>d[x]) {dd[y]=d[x]; notify(y);}
    }
    if(d[n]==INF) puts("-1");
    else 
    {
        printf("%d\n",d[n]);
        int now=n;
        while(now!=0)
        {
            printf("%d ",to[now]);
            now=to[now]+b[to[now]];
        }
        puts("");
    }
    return 0;
}