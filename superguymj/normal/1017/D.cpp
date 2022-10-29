#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=500005,M=15,K=(1<<14);
int n,m,q,w[20],a[K],bt[K];
typedef long long LL;
LL ans[K][105];
char s[N][M],t[M];

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
	n=getint(),m=getint(),q=getint();
	rep(i,1,n) w[i]=getint();
	rep(i,1,m) scanf("%s",s[i]);
	rep(i,0,(1<<n)-1) rep(j,0,n-1) if(i&(1<<j)) a[i]+=w[j+1];
	rep(i,1,m)
	{
		int x=0;
		rep(j,0,n-1) if(s[i][j]=='1') x|=(1<<j);
		++bt[x];
	}
	rep(i,0,(1<<n)-1)
		rep(j,0,(1<<n)-1)
			if(bt[j])
			{
				int x=((1<<n)-1)^i^j;
				if(a[x]<=100) ans[i][a[x]]+=bt[j];
			}
	rep(i,0,(1<<n)-1) rep(j,1,100) ans[i][j]+=ans[i][j-1];
	while(q--)
	{
		scanf("%s",t);
		int x=0;
		rep(i,0,n-1) if(t[i]=='1') x|=(1<<i);
		printf("%lld\n",ans[x][getint()]);
	}
	return 0;
}