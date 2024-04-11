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
#define MAXN 110000
int X[MAXN],Y[MAXN];
int n;
int sum[3005][3005];
int f1[3005][3005];
int f2[3005][3005];
int main()
{
	scanf("%d",&n);
	rep(p,1,n){
		int x1,x2,y1,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		rep(i,x1+1,x2)rep(j,y1+1,y2)sum[i][j]++;
		rep(i,x1+1,x2)f2[i][y1+1]=f2[i][y2+1]=1;
		rep(i,y1+1,y2)f1[x1+1][i]=f1[x2+1][i]=1;
		X[p]=x1+1;Y[p]=y1+1;
	}
	rep(i,1,3001)rep(j,1,3001){
		sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		f1[i][j]+=f1[i][j-1];
		f2[i][j]+=f2[i-1][j];
	}
	rep(i,1,n)
	{
		int x=X[i];int y=Y[i];int t=1;
		for(;;)
		{
			if(sum[x][y]-sum[X[i]-1][y]-sum[x][Y[i]-1]+sum[X[i]-1][Y[i]-1]!=t*t)break;
			
			if(f1[X[i]][y]-f1[X[i]][y-1]==0)break;
			if(f2[x][Y[i]]-f2[x-1][Y[i]]==0)break;
			
			if(f1[x+1][y]-f1[x+1][Y[i]-1]==t)
			if(f2[x][y+1]-f2[X[i]-1][y+1]==t)
			{
				int tot=0;
				rep(j,1,n)if(X[i]<=X[j]&&X[j]<=x)if(Y[i]<=Y[j]&&Y[j]<=y)tot++;
				printf("YES %d\n",tot);
				rep(j,1,n)if(X[i]<=X[j]&&X[j]<=x)if(Y[i]<=Y[j]&&Y[j]<=y)
				printf("%d ",j);
				return 0;
			}
			t++;x++;y++;
		}
	}
	printf("NO\n");
	return 0;	
}