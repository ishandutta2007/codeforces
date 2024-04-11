#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int tot,n;
ll t[MAXN],x[MAXN];
int get_dist(int x,int y)
{
    return max(x-y,y-x);
}
int main()
{
    scanf("%d",&tot);
    while(tot--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld%lld",&t[i],&x[i]);
        t[n+1]=INF;
        ll ct=0,st=0,ed=0,ans=0;
        for(int i=1;i<=n;i++)
        {
            if(ct+get_dist(st,ed)<=t[i])
            {
                if(get_dist(ed,x[i])<=t[i+1]-t[i]) ans++;
                ct=t[i];
                st=ed;
                ed=x[i];
            }
            else
            {
                if((x[i]>=st&&x[i]<=ed)||(x[i]>=ed&&x[i]<=st))
                {
                    if(get_dist(st,x[i])>=t[i]-ct&&get_dist(st,x[i])<=t[i+1]-ct) ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}