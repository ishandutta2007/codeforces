#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=505;
int n,a[N];
int f[2][N][N],ans;

void chkmax(int &x,int y)
{
	if(x<y) x=y;
}

int main()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	memset(f,-1,sizeof(f));
	f[0][0][0]=0;
	int tp=0;
	rep(i,1,n)
	{
		tp^=1;
		rep(j,1,n) rep(k,0,n) 
		{
			f[tp][j][k]=-1;
			if(f[tp^1][j][k]>-1)
				chkmax(f[tp][j][k],f[tp^1][j][k]+a[j]);
			chkmax(f[tp^1][j][k],f[tp^1][j-1][k]);
		}
		rep(k,1,n) if(f[tp^1][i-1][k-1]>-1)
			chkmax(f[tp][i][k],f[tp^1][i-1][k-1]+a[i]);
		rep(j,i+1,n) rep(k,0,n-(j-i-1)) if(f[tp^1][j-1][k+(j-i-1)]>-1)
			chkmax(f[tp][j][k],f[tp^1][j-1][k+(j-i-1)]+a[j]);
	}
	ans=0;
	rep(i,1,n) rep(j,0,n) chkmax(ans,f[tp][i][j]);
	printf("%d\n",ans);
	return 0;
}