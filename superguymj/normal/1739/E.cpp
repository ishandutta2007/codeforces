#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=200005;
int n;
char s[2][N];
int f[N][2][3],nxt[2][N],ans;

void chkmax(int &x,int y)
{
	if(x<y) x=y;
}

int main()
{
	scanf("%d",&n);
	rep(i,0,1) scanf("%s",s[i]+1);
	ans=-1;
	rep(i,1,n) rep(j,0,1) rep(k,0,2) f[i][j][k]=-1;
	nxt[0][n+1]=nxt[1][n+1]=2*n+1;
	rep(i,0,1)
		repd(j,n,1) 
			if(s[i][j]=='1') nxt[i][j]=j; 
			else nxt[i][j]=nxt[i][j+1];
	f[1][0][0]=0;
	rep(i,1,n) rep(k,0,2) rep(j,0,1) if(f[i][j][k]>-1)
	{
		int t=f[i][j][k];
		int x=nxt[j][i+1]-i;
		int y=nxt[j^1][i+k]-i+1;
		ans=max(ans,t);
		if(x>n && y>n) continue;
		if(x<y) 
			chkmax(f[nxt[j][i+1]][j][max(0,k-x)],t+1);
		if(x>y)
		{
			chkmax(f[nxt[j^1][i+k]][j^1][y==1],t+1);
			if(nxt[j][i+1]<=n)
				chkmax(f[nxt[j][i+1]][j][0],t+1);
		}
		if(x==y)
		{
			chkmax(f[nxt[j][i+1]][j][0],t+1);
			chkmax(f[nxt[j^1][i+k]][j^1][2],t+1);
		}
	}
	printf("%d\n",ans);
	return 0;
}