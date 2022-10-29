#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=5005,INF=1000000000;
int n,a[N],f[N][N][3];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

int main()
{
	n=getint();
	rep(i,1,n) a[i]=getint();
	rep(i,1,n) rep(j,0,n) rep(k,0,2) f[i][j][k]=INF;
	f[1][1][0]=0,f[1][0][1]=0;
	rep(i,2,n)
		rep(j,0,(n-1)/2+1)
		{
			if(j) f[i][j][0]=min(f[i][j][0],f[i-1][j-1][1]+max(0,a[i-1]-a[i]+1));
			if(j && i>2) f[i][j][0]=min(f[i][j][0],f[i-1][j-1][2]+max(0,min(a[i-1],a[i-2]-1)-a[i]+1));
			f[i][j][1]=min(f[i-1][j][1],f[i-1][j][2]);
			f[i][j][2]=f[i-1][j][0]+max(0,a[i]-a[i-1]+1);
		}
	rep(j,1,(n-1)/2+1) printf("%d ",min(min(f[n][j][0],f[n][j][1]),f[n][j][2]));
	puts("");
	return 0;
}