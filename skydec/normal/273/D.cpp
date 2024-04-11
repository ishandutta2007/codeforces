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
#define jsb 1000000007
int n,m;
int f[155][2][2][155][155];
int sum[155][2][2][155][155];
void add(int &x,int y){x+=y;if(x>=jsb)x-=jsb;}
int main()
{
	scanf("%d%d",&n,&m);int ans=0;
	rep(i,1,n)
	{
		rep(j,1,m)rep(k,j,m)rep(f1,0,1)rep(f2,0,1)rep(f3,0,f1)rep(f4,0,f2)
		add(f[i][f1][f2][j+f2-f4][k-f1+f3],f[i-1][f3][f4][j][k]);
		
		//rep(j,1,m)rep(k,j,m)rep(f1,0,1)rep(f2,0,1)sum[i][f1][f2][j][k]=f[i][f1][f2][j][k];
		rep(k,1,m)rep(j,1,k-1)
		{
			add(f[i][0][1][j+1][k],f[i][0][1][j][k]);
			add(f[i][1][1][j+1][k],f[i][1][1][j][k]);
		}
		rep(j,1,m)rep(k,j,m-1)
		{
			add(f[i][0][0][j][k+1],f[i][0][0][j][k]);
			add(f[i][0][1][j][k+1],f[i][0][1][j][k]);
		}
		rep(j,1,m)per(k,m,j+1)
		{
			add(f[i][1][0][j][k-1],f[i][1][0][j][k]);
			add(f[i][1][1][j][k-1],f[i][1][1][j][k]);
		}
		rep(k,1,m)per(j,k,2)
		{
			add(f[i][0][0][j-1][k],f[i][0][0][j][k]);
			add(f[i][1][0][j-1][k],f[i][1][0][j][k]);
		}
		rep(j,1,m)rep(k,j,m)add(f[i][0][0][j][k],1);
		rep(j,1,m)rep(k,j,m)rep(f1,0,1)rep(f2,0,1)add(ans,f[i][f1][f2][j][k]);
	}
	printf("%d\n",ans);
	return 0;
}