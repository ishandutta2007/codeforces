#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
const int mx=500010;
vector<pair<int,pi> >rbv;
int pa[mx],sz[mx];
inline void init(int n)
{
    fill(pa,pa+n+1,0);
    fill(sz,sz+n+1,1);
    return;
}
inline int par(int x)
{
    while(pa[x]!=0)
        x=pa[x];
    return x;
}
inline void uni(int x,int y,int p)
{
    x=par(x);
    y=par(y);
    if(x==y)
        return;
    if(sz[x]>sz[y])
        swap(x,y);
    rbv.eb(p,pi(x,0));
    rbv.eb(p,pi(y,sz[y]));
    pa[x]=y;
    sz[y]+=sz[x];
    return;
}
inline void rb(pi p)
{
    (p.se==0?pa[p.fi]:sz[p.fi])=p.se;
    return;
}
inline void rb(int p)
{
    while(!rbv.empty()&&rbv.back().fi==p)
    {
        rb(rbv.back().se);
        rbv.pop_back();
    }
    return;
}
vector<pi>ev[mx*4];
vector<int>qv[mx];
void put(int n,int s,int e,int S,int E,pi r)
{
    if(s>E||S>e)
        return;
    if(S<=s&&e<=E)
    {
        ev[n].eb(r);
        return;
    }
    int m=s+(e-s)/2;
    put(n*2,s,m,S,E,r);
    put(n*2+1,m+1,e,S,E,r);
    return;
}
bool chk[mx*4];
void dnc1(int n,int s,int e)
{
    if(s==e)
    {
        if(!qv[s].empty())
            chk[n]=1;
        return;
    }
    int m=s+(e-s)/2;
    dnc1(n*2,s,m);
    dnc1(n*2+1,m+1,e);
    chk[n]=chk[n*2]||chk[n*2+1];
    return;
}
void dnc(int n,int s,int e)
{
    if(!chk[n])
        return;
    for(pi&t:ev[n])
        uni(t.fi,t.se,n);
    if(s==e)
    {
        for(int&t:qv[s])
            cout<<sz[par(t)]<<'\n';
        rb(n);
        return;
    }
    int m=s+(e-s)/2;
    dnc(n*2,s,m);
    dnc(n*2+1,m+1,e);
    rb(n);
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q,k;
    cin>>n>>q>>k;
    vector<pair<int,pi> >rqv;
    vector<int>ps;
    int d=0;
    for(int i=0;i<q;i++)
    {
        int t=0,a=0,b=0;
        cin>>t;
        if(t==1)
            cin>>a>>b;
        else if(t==2)
            cin>>a,qv[(int)rqv.size()].eb(a);
        else
            d++;
        if(t!=2)
            rqv.eb(t,pi(a,b)),ps.eb(d);
    }
    q=rqv.size();
    for(int i=0;i<q;i++)
    {
        int t=rqv[i].fi,a=rqv[i].se.fi,b=rqv[i].se.se;
        if(t==1)
        {
            int s=i,e=q-1;
            while(s<e)
            {
                int m=s+(e-s+1)/2;
                if(ps[m]-ps[i]>=k)
                    e=m-1;
                else
                    s=m;
            }
            put(1,0,q,i+1,s+1,pi(a,b));
        }
    }
    init(n);
    dnc1(1,0,q);
    dnc(1,0,q);
    return 0;
}