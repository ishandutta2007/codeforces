#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,ca[MAXN],cb[MAXN],p[MAXN];
bool vis[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&ca[i]);
        for(int i=1;i<=n;i++) scanf("%d",&cb[i]);
        for(int i=1;i<=n;i++) p[ca[i]]=cb[i];
        for(int i=1;i<=n;i++) vis[i]=false;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                int num=0,now=i;
                while(!vis[now])
                {
                    num++;
                    vis[now]=true;
                    now=p[now];
                }
                cnt+=num/2;
            }
        }
        ll ans=0;
        for(int i=1;i<=cnt;i++) ans+=2LL*(n+1-2*i);
        printf("%lld\n",ans);
    }
    return 0;
}