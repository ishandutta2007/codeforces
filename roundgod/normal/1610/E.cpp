#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
ll a[MAXN];
int num[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        a[n+1]=INF;
        int ans=n-2;
        for(int i=1;i<=n;i++)
        {
            int nxt=lower_bound(a+1,a+n+2,a[i]+1)-a;
            if(nxt==n+1) {ans=min(ans,i-1); continue;}
            int cnt=nxt-i+1,now=nxt;
            ll dif=a[nxt]-a[i];
            while(now<=n)
            {
                int nxt=lower_bound(a+1,a+n+2,a[now]+dif)-a;
                if(nxt==n+1) break;
                cnt++;
                dif+=a[nxt]-a[now];
                now=nxt;
            } 
            ans=min(ans,n-cnt);
        }
        printf("%d\n",ans);
    }
    return 0;
}