#include<bits/stdc++.h>
#define MAXLOGN 20
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int maxi,mini;
int res[MAXLOGN][MAXN],pa[MAXLOGN][MAXN];
int ans[MAXN];
int fans[MAXN];
int main()
{
    scanf("%d",&n);
    maxi=-INF; mini=INF;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        maxi=max(maxi,a[i]);
        mini=min(mini,a[i]);
    }
    if(mini*2>=maxi)
    {
        for(int i=1;i<=n;i++) printf("%d ",-1);
        return 0;
    }
    for(int i=n+1;i<=3*n;i++) a[i]=a[i-n];
    for(int i=1;i<=3*n;i++)
    {
        res[0][i]=a[i];
        pa[0][i]=i-1;
    }
    for(int k=0;k+1<MAXLOGN;k++)
    {
        for(int v=1;v<=3*n;v++)
        {
            if(!pa[k][v])
            {
                pa[k+1][v]=0;
                res[k+1][v]=res[k][v];
            }
            else
            {
                pa[k+1][v]=pa[k][pa[k][v]];
                res[k+1][v]=max(res[k][v],res[k][pa[k][v]]);
            }
        }
    }
    for(int i=1;i<=3*n+1;i++) ans[i]=fans[i]=INF;
    for(int i=2*n+1;i<=3*n;i++)
    {
        int now=a[i],v=i;
        for(int k=MAXLOGN-1;k>=0;k--)
            if(res[k][v]<=2*a[i]) v=pa[k][v];
        ans[v]=min(ans[v],i);
    }
    for(int i=3*n;i>=1;i--)
    {
        ans[i]=min(ans[i],ans[i+1]);
        int now=i%n;
        if(now==0) now=n;
        fans[now]=min(fans[now],ans[i]-i);
    }
    for(int i=1;i<=n;i++) printf("%d ",fans[i]);
    return 0;
}