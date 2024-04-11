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
#define MAXN 5005
int res=0;
int r[MAXN][MAXN];
char str[MAXN][MAXN];
int n,m;
int c[MAXN];
inline char getnext(){char p=getchar();while(p!='0'&&p!='1')p=getchar();return p;}
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,m)str[i][j]=getnext();
	rep(i,1,n)per(j,m,1)if(str[i][j]=='0')r[i][j]=0;else r[i][j]=r[i][j+1]+1;
	rep(j,1,m)
	{
		memset(c,0,sizeof c);
		rep(i,1,n)c[r[i][j]]++;
		int now=0;
		per(i,m,1)
		{
			now+=c[i];
			res=max(res,now*i);
		}
	}
	printf("%d\n",res);
}