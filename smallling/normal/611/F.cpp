#include<cstdio>
#include<algorithm>

#define N 500000
#define fi first
#define se second
#define mp make_pair
#define inf 1000000000
#define mo 1000000007
#define INF 100000000000000ll
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)

using namespace std;

pair<long long,int>q[2*N+10];
int nowx[2*N+10],nowy[2*N+10];
int n,m,Q,Maxx,Maxy,Minx,Miny,x,y,r,ans;

long long getx(int now)
{
    int nowans;
    if((nowans=min(nowx[-now+N],nowx[n-now+1+N]))!=inf)return nowans;
    if(x==0)return INF;
    if(x>0)
    {
        int bj=n-Maxx+1,dis=bj-now;
        dis=(dis-1)/x+1;
        return 1ll*dis*Q+nowx[n-(now+x*dis)+1+N];
    }
    else
    {
        int bj=-Minx,dis=now-bj;
        dis=(dis-1)/(-x)+1;
        return 1ll*dis*Q+nowx[-(now+x*dis)+N];
    }
}

long long gety(int now)
{
    int nowans;
    if((nowans=min(nowy[-now+N],nowy[m-now+1+N]))!=inf)return nowans;
    if(y==0)return INF;
    if(y>0)
    {
        int bj=m-Maxy+1,dis=bj-now;
        dis=(dis-1)/y+1;
        return 1ll*dis*Q+nowy[m-(now+y*dis)+1+N];
    }
    else
    {
        int bj=-Miny,dis=now-bj;
        dis=(dis-1)/(-y)+1;
        return 1ll*dis*Q+nowy[-(now+y*dis)+N];
    }
}

int main()
{
    scanf("%d%d%d",&Q,&m,&n);
    char ch=getchar();
    for(int i=-N;i<=N;i++)
        nowx[i+N]=nowy[i+N]=inf;
    for(int i=1;i<=Q;i++)
    {
        ch=getchar();
        if(ch=='R')x++;
        if(ch=='L')x--;
        if(ch=='U')y--;
        if(ch=='D')y++;
        Maxx=max(Maxx,x);
        Minx=min(Minx,x);
        Maxy=max(Maxy,y);
        Miny=min(Miny,y);
        if(nowx[x+N]==inf)nowx[x+N]=i;
        if(nowy[y+N]==inf)nowy[y+N]=i;
    }
    for(int i=1;i<=n;i++)
        q[++r]=mp(getx(i),1);
    for(int i=1;i<=m;i++)
        q[++r]=mp(gety(i),2);
    sort(q+1,q+1+r);
    for(int i=1;i<=r;i++)
    {
        if(q[i].se==1&&q[i].fi!=INF)(ans+=m*q[i].fi%mo)%=mo,n--;
        if(q[i].se==2&&q[i].fi!=INF)(ans+=n*q[i].fi%mo)%=mo,m--;
    }
    if(n&&m)puts("-1");
    else printf("%d",ans); 
}