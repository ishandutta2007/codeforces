#include<stdio.h>
#include<algorithm>
#define MAXN 3005
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
int n,a[MAXN],b[MAXN],c[MAXN],f[MAXN][2];
int main()
{
    scanf("%d",&n);rep(i,1,n)scanf("%d",&a[i]);rep(i,1,n)scanf("%d",&b[i]);rep(i,1,n)scanf("%d",&c[i]);f[1][0]=a[1];f[1][1]=b[1];
    rep(i,2,n){f[i][0]=max(f[i-1][0]+b[i],f[i-1][1]+a[i]);f[i][1]=max(f[i-1][1]+b[i],f[i-1][0]+c[i]);}
    printf("%d\n",f[n][0]);return 0;
}