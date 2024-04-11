#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
vector<P> G[MAXN];
void add_edge(int u,int v,int id)
{
    G[u].push_back(P(v,id));
    G[v].push_back(P(u,id));
}
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int ans[MAXN],tot;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v,i);
    }
    memset(ans,-1,sizeof(ans));
    for(int i=1;i<=n;i++) 
    {
        if((int)G[i].size()>=3)
        {
            for(auto p:G[i]) ans[p.S]=tot++;
            for(int i=0;i<n-1;i++) if(ans[i]==-1) ans[i]=tot++;
            for(int i=0;i<n-1;i++) printf("%d\n",ans[i]);
            return 0;
        }
    }
    for(int i=0;i<n-1;i++) printf("%d\n",i);
    return 0;
}