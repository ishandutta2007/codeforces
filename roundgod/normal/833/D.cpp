#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,col,val;};
int n,btsz;
vector<edge> G[MAXN];
bool centroid[MAXN];
int sz[MAXN],deep[MAXN],d[MAXN],pr[MAXN];
vector<P> vec;
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
int inv(int x) {return pow_mod(x,MOD-2);}
int getval(int type,int col)
{
    if(type==0) return 0;
    else if(type==1) return col?-2:1;
    else return col?1:-2;
}
int ans;
P getroot(int v,int p,int t)//search_centroid
{
    P res=P(INT_MAX,-1);
	int m=0;
    sz[v]=1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].to;
        if(to==p||centroid[to]) continue;
        res=min(res,getroot(to,v,t));
        m=max(m,sz[to]);
        sz[v]+=sz[to];
    }
    m=max(m,t-sz[v]);
    res=min(res,P(m,v));
    return res;
}
void getdeep(int v,int p,int type)
{
    vec.push_back(P(d[v],pr[v]));
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].to,col=G[v][i].col,val=G[v][i].val;
        if(to==p||centroid[to]) continue;
        d[to]=d[v]+getval(type,col);
        pr[to]=1LL*pr[v]*val%MOD;
        getdeep(to,v,type);
    }
}
int cal(int v,int type)
{
    vec.clear();
    getdeep(v,0,type);
    int res=1;
    if(type==0)
    {
        for(int i=0;i<(int)vec.size();i++)
            res=1LL*res*pow_mod(vec[i].S,(int)vec.size()-1)%MOD;
        return res;
    }
    else
    {
        sort(vec.begin(),vec.end(),greater<P>());
        int tmp=1;
        for(int i=1;i<(int)vec.size();i++) tmp=1LL*tmp*vec[i].S%MOD;
        int l=0,r=(int)vec.size()-1;
        while(l<r)
        {
            if(vec[l].F+vec[r].F>0)
            {
                res=1LL*res*tmp%MOD*pow_mod(vec[l].S,r-l)%MOD;
                l++; tmp=1LL*tmp*inv(vec[l].S)%MOD;
            }
            else
            {
                tmp=1LL*tmp*inv(vec[r].S)%MOD; r--;
            }
        }
        return res;
    }
}
void solve(int v)
{
    d[v]=0; pr[v]=1; 
    ans=1LL*ans*cal(v,0)%MOD;
    ans=1LL*ans*inv(cal(v,1))%MOD;
    ans=1LL*ans*inv(cal(v,2))%MOD;
    centroid[v]=true;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].to,col=G[v][i].col;
        if(centroid[to]) continue;
        pr[to]=G[v][i].val;
        d[to]=0; ans=1LL*ans*inv(cal(to,0))%MOD;
        d[to]=getval(1,col); ans=1LL*ans*cal(to,1)%MOD;
        d[to]=getval(2,col);  ans=1LL*ans*cal(to,2)%MOD;
        int rt=getroot(to,v,sz[to]).S;
        solve(rt);
    }
}
void ac()
{
    ans=1;
    int rt=getroot(1,0,n).S;
    solve(rt);
    printf("%d\n",ans);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v,x,c;
        scanf("%d%d%d%d",&u,&v,&x,&c);
        G[u].push_back((edge){v,c,x});
        G[v].push_back((edge){u,c,x});
    }
    memset(centroid,false,sizeof(centroid));
    ac();
    return 0;
}