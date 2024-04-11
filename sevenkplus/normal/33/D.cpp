#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
struct P{int x,y;}a[1010];
struct R{int x,y,r;}b[1010];
int n,m,k;bool f[1010][1010];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)scanf("%d%d",&a[i].x,&a[i].y);
    for(int i=0;i<m;i++)scanf("%d%d%d",&b[i].r,&b[i].x,&b[i].y);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(sqrt((ll)(a[i].x-b[j].x)*(a[i].x-b[j].x)+(ll)(a[i].y-b[j].y)*(a[i].y-b[j].y))<b[j].r)f[i][j]=1;
    for(int i=0;i<k;i++)
    {
        int x,y,S=0;
        scanf("%d%d",&x,&y),--x,--y;
        for(int i=0;i<m;i++)if(f[x][i]^f[y][i])S++;
        printf("%d\n",S);
    }
    return 0;
}