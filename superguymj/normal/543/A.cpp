#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=505;
int n,m,b,mod,a[N],f[N][N],ans;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void inc(int &x,int y)
{
	if((x+=y)>=mod) x-=mod;
}

int main()
{
	n=getint(),m=getint(),b=getint(),mod=getint();
	rep(i,1,n) a[i]=getint();
	f[0][0]=1;
	rep(i,1,n)
	{
		rep(j,0,m-1)
			rep(k,0,b-a[i])
				inc(f[j+1][k+a[i]],f[j][k]);
	}
	rep(i,0,b) inc(ans,f[m][i]);
	printf("%d\n",ans);
	return 0;
}