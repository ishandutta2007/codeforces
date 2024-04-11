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
#define jsb 1000000007
int f[MAXN];
int g[MAXN];
int n,a,b,k;
int main()
{
	scanf("%d%d%d%d",&n,&a,&b,&k);
	f[a]=1;
	rep(i,1,k){
		rep(j,1,n)if(f[j]){
			int u=j-b;if(u<0)u*=-1;u--;
			if(!u)continue;
			g[min(n,j+u)+1]=(g[min(n,j+u)+1]-f[j])%jsb;
			g[max(0,j-u)]=(g[max(0,j-u)]+f[j])%jsb;
			g[j]=(g[j]-f[j])%jsb;
			g[j+1]=(g[j+1]+f[j])%jsb;
		}
		f[0]=g[0];
		rep(j,1,n)f[j]=(f[j-1]+g[j])%jsb;
		memset(g,0,sizeof g);
	}
	int res=0;rep(i,1,n)res=(res+f[i])%jsb;res=(res+jsb)%jsb;
	printf("%d\n",res);
	return 0;
}