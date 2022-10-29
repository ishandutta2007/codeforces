#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=5005,mod=1000000007,inv2=(mod+1)/2;
int n,tp;
LL a[N],s[N],ans[N<<1],f[2][N][2];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

int main()
{
	n=getint(),s[1]=1;
	rep(i,1,n-1) a[i]=getint(),s[i+1]=s[i]*a[i]%mod;
	tp=1;
	rep(i,1,n)
	{
		f[1][i][1]=s[i+1];
		if(i>1) f[1][i][0]=s[i];
	}
	rep(i,1,n) ans[1]=(ans[1]+f[tp][i][0]+f[tp][i][1])%mod;
	rep(i,2,2*n-2) 
	{
		tp^=1;
		rep(j,1,n) f[tp][j][0]=f[tp][j][1]=0;
		rep(j,1,n)
		{
			LL tmp0=f[tp^1][j][0];
			LL tmp1=f[tp^1][j][1];
			f[tp][j+1][0]=(f[tp][j+1][0]+tmp0*a[j])%mod;
			f[tp][j-1][1]=(f[tp][j-1][1]+tmp1)%mod;
			f[tp][j+1][0]=(f[tp][j+1][0]+tmp1*(a[j]-1))%mod;
		}
		rep(j,1,n) ans[i]=(ans[i]+f[tp][j][0]+f[tp][j][1])%mod;
	}
	rep(i,1,2*n-2) printf("%lld\n",ans[i]*inv2%mod);
	return 0;
}