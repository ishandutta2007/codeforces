#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,p[MAXN];
int ldown[MAXN],lup[MAXN],rdown[MAXN],rup[MAXN];
int pre[MAXN],suf[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    ldown[0]=lup[0]=rdown[n+1]=rup[n+1]=0;
    for(int i=1;i<=n;i++)
    {
        if(i!=1&&p[i]>=p[i-1]) ldown[i]=ldown[i-1]+1;
        else ldown[i]=0;
        if(i!=1||p[i]<=p[i-1]) lup[i]=lup[i-1]+1;
        else lup[i]=0;
    }
    for(int i=n;i>=1;i--)
    {
        if(i!=n&&p[i]>=p[i+1]) rdown[i]=rdown[i+1]+1;
        else rdown[i]=0;
        if(i!=n&&p[i]<=p[i+1]) rup[i]=rup[i+1]+1;
        else rup[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        if(i==1) pre[i]=1;
        else if(i==2) pre[i]=2;
        else if((p[i]>=p[i-1])==(p[i-1]>=p[i-2])) pre[i]=pre[i-1]+1;
        else pre[i]=2;
    }
    for(int i=n;i>=1;i--)
    {
        if(i==n) suf[i]=1;
        else if(i==n-1) suf[i]=2;
        else if((p[i]>=p[i+1])==(p[i+1]>=p[i+2])) suf[i]=suf[i+1]+1;
        else suf[i]=2;
    }
    for(int i=1;i<=n;i++) pre[i]=max(pre[i-1],pre[i]);
    for(int i=n;i>=1;i--) suf[i]=max(suf[i+1],suf[i]);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(ldown[i]==0||rdown[i]==0) continue;
        if(ldown[i]!=rdown[i]) continue;
        if(ldown[i]%2==1) continue;
        if(i-ldown[i]>=1&&pre[i-ldown[i]]>=ldown[i]+1) continue;
        if(i+rdown[i]<=n&&suf[i+rdown[i]]>=ldown[i]+1) continue;
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}