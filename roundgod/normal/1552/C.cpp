#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k;
int x[MAXN],y[MAXN];
bool used[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        memset(used,false,sizeof(used)); 
        for(int i=1;i<=k;i++) 
        {
            scanf("%d%d",&x[i],&y[i]);
            if(x[i]>y[i]) swap(x[i],y[i]);
            used[x[i]]=used[y[i]]=true;
        }
        int ans=(n-k)*(n-k-1)/2;
        for(int i=1;i<=k;i++)
            for(int j=i+1;j<=k;j++)
            {
                int cnt=0;
                if(x[j]>=x[i]&&x[j]<=y[i]) cnt++;
                if(y[j]>=x[i]&&y[j]<=y[i]) cnt++;
                if(cnt==1) ans++;
            }
        for(int i=1;i<=k;i++)
        {
            int cnt=0;
            for(int j=x[i]+1;j<=y[i]-1;j++) if(!used[j]) cnt++;
            ans+=min(cnt,2*n-2*k-cnt);
        }
        printf("%d\n",ans);
    }
    return 0;
}