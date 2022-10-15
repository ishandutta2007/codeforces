#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> G[2][MAXN];
int n,m;
bool update[MAXN];
P dis[2][MAXN];
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
bool gr(P u,P v)
{
    if(u.F==v.F) return u.S>v.S;
    if(max(u.F,v.F)>30) return u.F>v.F;
    return (1LL<<u.F)+u.S>(1LL<<v.F)+v.S;
}
int main()
{
    //freopen("C.in","r",stdin);
    //clock_t startTime,endTime;
    //startTime = clock();
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[0][u].push_back(v);
        G[1][v].push_back(u);
    }
    queue<P> que;
    for(int i=1;i<=n;i++) dis[0][i]=dis[1][i]=P(-1,-1);
    dis[0][1]=P(0,0);
    que.push(P(1,0));
    vector<P> upd;
    upd.push_back(P(0,1));
    for(int i=0;;i++)
    {
        int id=i&1;
        while(que.size())
        {
            P p=que.front(); que.pop();
            int v=p.F,d=p.S;
            for(auto to:G[id][v])
            {
                if(dis[id][to].F==-1||gr(dis[id][to],P(i,d+1)))
                {
                    dis[id][to]=P(i,d+1);
                    que.push(P(to,d+1));
                    upd.push_back(P(d+1,to));
                }
            }
        }
        sort(upd.begin(),upd.end());
        for(auto p:upd) que.push(P(p.S,p.F));
        upd.clear();
        while(que.size())
        {
            P p=que.front(); que.pop();
            int v=p.F,d=p.S;
            for(auto to:G[id^1][v])
            {
                if(dis[id^1][to].F==-1||gr(dis[id^1][to],P(i+1,d+1)))
                {
                    dis[id^1][to]=P(i+1,d+1);
                    upd.push_back(P(d+1,to));
                }
            }
        }
        if(!upd.size()) break;
        for(auto p:upd) que.push(P(p.S,p.F));
    }
    assert(dis[0][n].F!=-1||dis[1][n].F!=-1);
    int ans;
    if(dis[1][n].F==-1||(dis[0][n].F!=-1&&gr(dis[1][n],dis[0][n]))) ans=(pow_mod(2,dis[0][n].F)-1+dis[0][n].S)%MOD;
    else ans=(pow_mod(2,dis[1][n].F)-1+dis[1][n].S)%MOD;
    if(ans<0) ans+=MOD;
    printf("%d\n",ans);
    //cout << "The run time is:" << (double)clock() /CLOCKS_PER_SEC<< "s" << endl;
}