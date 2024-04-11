#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<cmath>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=1000005,INF=10000000;
int f[7][7],g[7][7],n,m,a[N],ans;
int x,y,z;

void ins()
{
	rep(i,0,6) rep(j,0,6) g[i][j]=-INF;
	rep(i,0,6) rep(j,0,6) if(f[i][j]>=0)
		rep(k,0,6)
		{
			if(k<=z && j+k<=y && i+k<=x)
			{
				g[j+k][k]=max(g[j+k][k],f[i][j]+(x-i-k)/3+k);
			}
			else break;
		}
	memcpy(f,g,sizeof(g));
}	

int main()
{
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d",&x),++a[x];
	if(m==1) return printf("%d\n",a[1]/3),0;
	rep(i,0,6) rep(j,0,6) f[i][j]=-INF;
	f[0][0]=0;
	rep(i,3,m)
	{
		x=a[i-2];
		y=a[i-1];
		z=a[i],ins();
	}
	x=a[m-1],y=a[m];
	rep(i,0,6) rep(j,0,6) ans=max(ans,f[i][j]+(x-i)/3+(y-j)/3);
	printf("%d\n",ans);
	return 0;
}