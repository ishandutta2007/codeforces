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
using namespace std;
#define MAXN 2005
char str[MAXN];char p[MAXN];int n,m;
int near[MAXN];int next[MAXN];int tmp[MAXN];
int f[MAXN][MAXN];int na[MAXN];
int Max(int &a,int b){if(b>a)a=b;}
int main()
{
	scanf("%s",str+1);scanf("%s",p+1);n=strlen(str+1);m=strlen(p+1);
	rep(i,1,n)
	{
		int now=1;
		if(str[i]!=p[1])continue;
		rep(j,i,n)
		{
			if(p[now]==str[j])now++;
			if(now>m)
			{
				near[i]=j;
				break;
			}
		}
		//printf("near[%d]=%d\n",i,near[i]);
	}
	rep(i,0,n)rep(j,0,n)f[i][j]=-2100000000;f[0][0]=0;
	rep(i,0,n)
	rep(j,0,i)
	{
		if(j+1<=n&&i)
		Max(f[i+1][j+1],f[i][j]);
		Max(f[i+1][j],f[i][j]);
		if(near[i])
		{
			if(near[i]-i+1-m+j<=n)
			Max(f[near[i]+1][near[i]-i+1-m+j],f[i][j]+1);
		}
		//printf("f[%d][%d]=%d\n",i,j,f[i][j]);
	}
	rep(i,0,n)printf("%d ",max(f[n][i],f[n+1][i]));
	return 0;
}