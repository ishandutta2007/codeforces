#include<stdio.h>
#include<cstring>
#define MAXN 2005
using namespace std;
typedef long long LL;
LL data[MAXN][MAXN];
LL l[MAXN*2],r[MAXN*2];
int n;
struct Ans
{
       int x,y;
       LL val;
}ans[2];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
            scanf("%I64d",&data[i][j]);
            l[i+j]+=data[i][j];
            r[i-j+n]+=data[i][j];
            }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
            Ans p;
            p.val=l[i+j]+r[i-j+n]-data[i][j];
            p.x=i;
            p.y=j;
            if(p.val>=ans[(i+j)&1].val)ans[(i+j)&1]=p;
            }
    printf("%I64d\n",ans[0].val+ans[1].val);
    printf("%d %d %d %d\n",ans[0].x,ans[0].y,ans[1].x,ans[1].y);
    return 0;
}