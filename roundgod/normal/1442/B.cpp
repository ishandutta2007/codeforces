#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],b[MAXN],pos[MAXN];
int rk[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) rk[i]=0;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            pos[a[i]]=i;
        }
        a[n+1]=0;
        rk[0]=k+1;
        for(int i=1;i<=k;i++)
        {
            scanf("%d",&b[i]);
            rk[b[i]]=i;
        }
        int ans=1;
        for(int i=1;i<=k;i++)
        {
            int p=pos[b[i]];
            int cnt=(rk[a[p-1]]<=rk[b[i]])+(rk[a[p+1]]<=rk[b[i]]);
            ans=1LL*ans*cnt%MOD;
        }
        printf("%d\n",ans);
    }
    return 0;
}