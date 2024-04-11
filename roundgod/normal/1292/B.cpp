#include<bits/stdc++.h>
#define MAXN 100005
#define INF 2000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
#define x0 dasokdaso
#define y0 dskados
#define x1 dsakodaso
#define y1 daskpodasp
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll x0,y0,ax,ay,bx,by,t,xs,ys;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
ll get_dist(ll x0,ll y0,ll x1,ll y1)
{
    return max(x0-x1,x1-x0)+max(y0-y1,y1-y0);
}
vector<P> v;
int main()
{
    scanf("%lld%lld%lld%lld%lld%lld",&x0,&y0,&ax,&ay,&bx,&by);
    scanf("%lld%lld%lld",&xs,&ys,&t);
    v.push_back(P(x0,y0));
    do
    {
        if(INF/x0<ax||INF/y0<ay) break;
        x0=x0*ax+bx; y0=y0*ay+by;
        v.push_back(P(x0,y0));
    } while (true);
    int ans=0;
    for(int i=0;i<(int)v.size();i++)
    {
        if(get_dist(xs,ys,v[i].F,v[i].S)>t) continue;
        int cnt=1;
        ll tmp=t-get_dist(xs,ys,v[i].F,v[i].S);
        for(int j=i-1;j>=0;j--)
        {
            if(get_dist(v[j].F,v[j].S,v[j+1].F,v[j+1].S)>tmp) break;
            cnt++;
            tmp-=get_dist(v[j].F,v[j].S,v[j+1].F,v[j+1].S);
        }
        ans=max(ans,cnt);
    }
    for(int i=0;i<(int)v.size();i++)
    {
        if(get_dist(xs,ys,v[i].F,v[i].S)>t) continue;
        int cnt=1;
        ll tmp=t-get_dist(xs,ys,v[i].F,v[i].S);
        for(int j=i+1;j<(int)v.size();j++)
        {
            if(get_dist(v[j].F,v[j].S,v[j-1].F,v[j-1].S)>tmp) break;
            cnt++;
            tmp-=get_dist(v[j].F,v[j].S,v[j-1].F,v[j-1].S);
        }
        ans=max(ans,cnt);
    }
    printf("%d\n",ans);
    return 0;
}