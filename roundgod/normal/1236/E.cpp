#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
int s,t,cnt[MAXN];
int offset=200000;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d",&a[i]);
    if(n==1&&m>0)
    {
        puts("0");
        return 0;
    }
    ll ans=n;
    for(int i=1;i<=n;i++) cnt[i]=1;
    s=1;
    for(int i=1;i<=m;i++)
    {
        int pos=a[i]+s;
        cnt[pos+1]+=cnt[pos];
        cnt[pos]=0;
        ans-=cnt[s];
        s++;
    }
    ans-=cnt[s]; s++;
    for(int i=s;i<=300005;i++) ans-=1LL*(i-s+1)*cnt[i];
    memset(cnt,0,sizeof(cnt));
    for(int i=offset+1;i<=offset+n;i++) cnt[i]=1;
    t=offset+n;
    for(int i=1;i<=m;i++)
    {
        int pos=t-n+a[i]-1;
        cnt[pos-1]+=cnt[pos];
        cnt[pos]=0;
        ans+=1LL*n*cnt[t];
        t--;
    }
    ans+=1LL*n*cnt[t]; t--;
    for(int i=t;i>=0;i--) ans+=1LL*(n-t+i)*cnt[i];
    printf("%lld\n",ans);
    return 0;
}