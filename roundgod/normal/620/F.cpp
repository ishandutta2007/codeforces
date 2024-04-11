#include<bits/stdc++.h>
#define MAXN 50005
#define MAXM 5005
#define MAXK 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int a[MAXN];
int l[MAXM],r[MAXM];
int f[MAXK];
int ans[MAXM];
int maxi[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    f[1]=1;
    for(int i=2;i<=1000000;i++) f[i]=f[i-1]^i;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d%d",&l[i],&r[i]);
    for(int i=1;i<=n;i++)
    {
        memset(maxi,0,sizeof(maxi));
        for(int j=i;j<=n;j++)
        {
            int val=f[a[i]]^f[a[j]]^(a[i]<a[j]?a[i]:a[j]);
            maxi[j]=max(maxi[j-1],val);
        }
        for(int j=1;j<=m;j++)
        {
            if(l[j]<=i&&i<=r[j]) ans[j]=max(ans[j],maxi[r[j]]);
        }
    }
    for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
    return 0;
}