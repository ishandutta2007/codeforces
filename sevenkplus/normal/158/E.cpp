#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
#define mp make_pair
#define fi first
#define se second
#define INF 1000000007
#define N 4010
int n,m,f[N][N],S;PII a[N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i].fi,&a[i].se);
    sort(a+1,a+n+1),a[n+1]=mp(86401,0);
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
            f[i][j]=min(j?f[i-1][j-1]:INF,a[i].fi<=f[i-1][j]?f[i-1][j]+a[i].se:a[i].fi+a[i].se-1);
    for(int i=1;i<=n+1;i++)S=max(S,a[i].fi-f[i-1][m]-1);
    printf("%d\n",S);
    return 0;
}