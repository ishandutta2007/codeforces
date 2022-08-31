#include<stdio.h>
#include<cstring>
#include<algorithm>
#define fi first
#define se second
#define mk make_pair
#define pii pair<int,int>
#define MAXN 310000
using namespace std;
int f[2][MAXN];
pair<int,pair <int,int> > bmap[MAXN];
int n,m;
void MAX(int &x,int y){if(y>x)x=y;}
int main()
{
    scanf("%d%d",&n,&m);int now=0;
    for(int i=1;i<=m;i++)
    {
            int a,b,c;scanf("%d%d%d",&a,&b,&c);
            bmap[i]=mk(c,pii(a,b));
            }
    sort(bmap+1,bmap+1+m);
    for(int i=1;i<=m;i++)
    {
            //printf("%d %d %d\n",bmap[i].fi,bmap[i].se.fi,bmap[i].se.se);
            int j=i;
            while(i<m&&bmap[j+1].fi==bmap[i].fi)j++;
            for(int k=i;k<=j;k++)MAX(f[1][bmap[k].se.se],f[0][bmap[k].se.fi]+1);
            for(int k=i;k<=j;k++)MAX(f[0][bmap[k].se.se],f[1][bmap[k].se.se]);
            i=j;
            }
    //printf("%d %d %d\n",f[0][1],f[0][2],f[0][3]);
    int u=0;for(int i=1;i<=n;i++)MAX(u,f[0][i]);
    printf("%d\n",u);
    return 0;
}