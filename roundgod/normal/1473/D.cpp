#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,sum[MAXN],premax[MAXN],sufmax[MAXN],premin[MAXN],sufmin[MAXN];
string str;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n+1;i++) sum[i]=premax[i]=sufmax[i]=premin[i]=sufmin[i]=0;
        cin>>str;
        for(int i=1;i<=n;i++)
        {
            sum[i]=(str[i-1]=='-'?-1:1);
            sum[i]+=sum[i-1];
        }
        sufmin[n+1]=INF; sufmax[n+1]=-INF;
        for(int i=1;i<=n;i++) 
        {
            premax[i]=max(premax[i-1],sum[i]);
            premin[i]=min(premin[i-1],sum[i]);
        }
        for(int i=n;i>=1;i--)
        {
            sufmax[i]=max(sufmax[i+1],sum[i]);
            sufmin[i]=min(sufmin[i+1],sum[i]);
        }
        for(int i=0;i<m;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            int s=sum[r]-sum[l-1];
            int maxi=max(premax[l-1],sufmax[r+1]-s);
            int mini=min(premin[l-1],sufmin[r+1]-s);
            //printf("s=%d maxi=%d mini=%d\n",s,maxi,mini);
            printf("%d\n",maxi-mini+1);
        }
    }
    return 0;
}