#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
#define mp make_pair
#define fi first
#define se second
#define N 100010
int n,m,x,y,a[N],b[N],S;PII A[N];
int main()
{
    scanf("%d%d%d%d",&n,&m,&x,&y);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=m;i++)scanf("%d",b+i);
    for(int i=1,j=1;i<=n;i++)
    {
        while(j<=m&&b[j]<a[i]-x)j++;
        if(j<=m&&b[j]<=a[i]+y)A[++S]=mp(i,j),j++;
    }
    printf("%d\n",S);
    for(int i=1;i<=S;i++)
        printf("%d %d\n",A[i].fi,A[i].se);
    return 0;
}