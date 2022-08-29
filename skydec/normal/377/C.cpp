#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
#define inf 1000000000
using namespace std;
int f[1<<20];int gt[125];int rest[1<<20];
char ms[25];int who[25];
int n,m;bool cmp(int a,int b){return a>b;}
int main()
{
	scanf("%d",&n);rep(i,1,n)scanf("%d",&gt[i]);
	sort(gt+1,gt+1+n,cmp);scanf("%d",&m);
	rep(i,1,m){char opt[3];scanf("%s",opt);ms[i]=opt[0];scanf("%d",&who[i]);}
	rest[0]=1;rep(i,1,((1<<m)-1))rest[i]=rest[i-lowbit(i)]+1;
	per(i,(1<<m)-2,0)
	if(who[rest[i]]==1)
	{
		f[i]=-inf;
		rep(j,1,m)if(!((1<<(j-1))&i))f[i]=max(f[i],f[i+(1<<(j-1))]+gt[j]*(ms[rest[i]]=='p'));
	}
	else
	{
		f[i]=inf;
		rep(j,1,m)if(!((1<<(j-1))&i))f[i]=min(f[i],f[i+(1<<(j-1))]-gt[j]*(ms[rest[i]]=='p'));
	}
	printf("%d\n",f[0]);return 0;
}