#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
using namespace std;
typedef long long ll;
struct edge{int u,v,cost;};
bool cmp(const edge &e1,const edge &e2)
{
    return e1.cost<e2.cost;
}
vector<edge> es;
int t,n,m,k,cnt;
int p[MAXN],r[MAXN];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    cnt--;
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        es.clear();
        scanf("%d%d%d",&n,&m,&k);
        cnt=n;
        init(n);
        for(int i=0;i<m;i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            es.push_back((edge){u,v,c});
        }
        ll ans=INF,res=0,maxi=INF,mini=INF;
        int cnt=0;
        sort(es.begin(),es.end(),cmp);
        for(int i=0;i<m;i++)
        {
            edge e=es[i];
            if(e.cost>=k) maxi=min(maxi,1LL*(e.cost-k));
            else if(e.cost<=k) mini=min(mini,1LL*(k-e.cost));
            if(!same(e.u,e.v))
            {
                unite(e.u,e.v); cnt++;
                if(e.cost>k) res+=e.cost-k;
            }
        }
        assert(cnt==n-1);
        if(res>0) ans=res; else ans=min(maxi,mini); 
        printf("%lld\n",ans);
    }
    return 0;
}