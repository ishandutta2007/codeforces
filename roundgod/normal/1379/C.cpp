#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
int a[MAXN],b[MAXN];
vector<int> va;
vector<P> vb;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        va.clear(); vb.clear();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            va.push_back(a[i]);
            vb.push_back(P(b[i],i));
        }
        sort(va.begin(),va.end(),greater<int>());
        sort(vb.begin(),vb.end(),greater<P>());
        int now=0;
        int cnt=0;
        ll s=0;
        ll ans=0;
        for(int i=0;i<m;i++)
        {
            while(now<m&&va[now]>=vb[i].F) {cnt++; s+=va[now]; now++;}
            if(a[vb[i].S]>=vb[i].F)
            {
                if(cnt<=n)
                {
                    ans=max(ans,1LL*vb[i].F*(n-cnt)+s);
                }
            }
            else
            {
                if(cnt+1<=n) ans=max(ans,1LL*vb[i].F*(n-cnt-1)+s+a[vb[i].S]);
            }
        }
        s=0;
        if(m>=n)
        {
            for(int i=0;i<n;i++) s+=va[i];
            ans=max(ans,s);
        }
        printf("%lld\n",ans);
    }
    return 0;
}