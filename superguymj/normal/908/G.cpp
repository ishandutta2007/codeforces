#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=705,mod=1000000007;
typedef long long LL;
int n;
char s[N];
LL f[N][N][2],g[N][N][2],ans;

void inc(LL &x,LL y)
{
	x=(x+y)%mod;
}

void solve(int x)
{
	memset(f,0,sizeof(f)),memset(g,0,sizeof(g));
	f[0][0][1]=1,g[0][0][1]=0;
	rep(i,1,n)
	{
		rep(j,0,n)
		{
			if(f[i-1][j][0])
			{
				LL F=f[i-1][j][0],G=g[i-1][j][0];
				rep(k,0,9)
				{
					if(k!=x) inc(f[i][j+(k>x)][0],F),inc(g[i][j+(k>x)][0],G);
					else inc(f[i][j][0],F),inc(g[i][j][0],G*10+x*F);
				}
			}
			if(f[i-1][j][1])
			{
				LL F=f[i-1][j][1],G=g[i-1][j][1];
				rep(k,0,s[i]-48)
				{
					if(k!=x) inc(f[i][j+(k>x)][k==(s[i]-48)],F),inc(g[i][j+(k>x)][k==(s[i]-48)],G);
					else inc(f[i][j][k==(s[i]-48)],F),inc(g[i][j][k==(s[i]-48)],G*10+x*F);
				}
			}
		}
	}
	LL pw=1;
	rep(i,0,n) ans=(ans+(g[n][i][0]+g[n][i][1])*pw)%mod,pw=pw*10%mod;
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	rep(i,1,9) solve(i);
	printf("%lld\n",ans);
	return 0;
}