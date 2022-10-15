#include<bits/stdc++.h>
#define MAXN 200015
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k1,k2,k3;
int type[MAXN];
int pre[MAXN],suf[MAXN],tmp,ans;
int main()
{
    scanf("%d%d%d",&k1,&k2,&k3);
    n=k1+k2+k3;
    for(int i=0;i<k1;i++)
    {
        int x;
        scanf("%d",&x);
        type[x]=1;
    }
    for(int i=0;i<k2;i++)
    {
        int x;
        scanf("%d",&x);
        type[x]=2;
    }
    for(int i=0;i<k3;i++)
    {
        int x;
        scanf("%d",&x);
        type[x]=3;
    }
    for(int i=1;i<=n;i++)
    {
        if(type[i]==1)
        {
            tmp++;
            pre[i]--;
        }
        else if(type[i]==3)
        {
            tmp++;
            suf[0]--; suf[i+1]++;
        }
        else
        {
            pre[i]++;
            suf[0]++; suf[i+1]--;
        }
    }
    for(int i=1;i<=n;i++) pre[i]+=pre[i-1];
    for(int i=1;i<=n+1;i++) suf[i]+=suf[i-1];
    for(int i=n;i>=1;i--) suf[i]=min(suf[i],suf[i+1]);
    int ans=INF;
    for(int i=0;i<=n;i++) ans=min(ans,pre[i]+suf[i+1]);
    printf("%d\n",ans+tmp);
    return 0;
}