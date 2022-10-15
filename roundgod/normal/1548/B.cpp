#include<bits/stdc++.h>
#define MAXN 200005
#define MAXLOGN 19
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
ll a[MAXN],d[MAXN],g[MAXLOGN][MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n-1;i++) {d[i]=max(a[i]-a[i+1],a[i+1]-a[i]); g[0][i]=d[i];}
        for(int i=0;i<18;i++)
            for(int j=1;j+(1<<(i+1))-1<=n-1;j++)
                g[i+1][j]=__gcd(g[i][j],g[i][j+(1<<i)]);
        int ans=1;
        for(int i=1;i<=n-1;i++)
        {
            int now=i; ll gg=0;
            for(int j=18;j>=0;j--)
            {
                if(now+(1<<j)-1<=n-1&&__gcd(gg,g[j][now])>1)
                {
                    gg=__gcd(gg,g[j][now]);
                    now+=(1<<j);
                }
            }
            if(d[i]==1) continue;
            else ans=max(ans,now-i+1);
        }
        printf("%d\n",ans);
    }
    return 0;
}