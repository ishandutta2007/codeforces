#include<bits/stdc++.h>
#define MAXN 500005
#define MAXD 40
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int q,tot,fa[MAXN];
double dp[MAXN][40];
double tmp[40];
double p[105];
int main()
{
    p[0]=1.0;
    for(int i=1;i<100;i++) p[i]=0.5*p[i-1];
    tot=1; fa[1]=0;
    for(int i=0;i<40;i++) dp[1][i]=1.0;
    scanf("%d",&q);
    while(q--)
    {
        int type,v;
        scanf("%d%d",&type,&v);
        if(type==1)
        {
            ++tot;
            fa[tot]=v;
            int cur=v;
            for(int i=1;i<40;i++)
            {
                if(!fa[cur]) break;
                tmp[i]=dp[fa[cur]][i]/(0.5+0.5*dp[cur][i-1]);
                cur=fa[cur];
            }
            cur=v;
            for(int i=1;i<40;i++)
            {
                if(!fa[cur]) break;
                dp[fa[cur]][i]=tmp[i];
                cur=fa[cur];
            }
            for(int i=0;i<40;i++) dp[tot][i]=1.0;
            dp[v][0]*=0.5;
            cur=v;
            for(int i=1;i<40;i++)
            {
                if(!fa[cur]) break;
                dp[fa[cur]][i]*=(0.5+0.5*dp[cur][i-1]);
                cur=fa[cur];
            }
        }
        else
        {
            double ans=0.0;
            for(int i=0;i<40;i++) if(i) ans+=i*(dp[v][i]-dp[v][i-1]);
            printf("%.10f\n",ans);
        }
    }
    return 0;
}