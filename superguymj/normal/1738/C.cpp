#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
typedef long long LL;
const int N=105;
int n,m;
bool f[N][N][2][2];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

void init()
{
	n=100;
	rep(i,0,1) f[0][0][0][i]=1;
	rep(i,1,n)
		rep(j,0,i)
			rep(k,0,1)
			{
				int a=0,b=0;
				if(j && f[i-1][j-1][k^1][1]) a=1;
				if(i-j && f[i-1][j][k][1]) b=1;
				if(a || b) f[i][j][k][0]=1;
				
				a=1,b=1;
				if(j && !f[i-1][j-1][k][0]) a=0;
				if(i-j && !f[i-1][j][k][0]) b=0;
				if(a && b) f[i][j][k][1]=1;
			}
}

void solve()
{
	n=getint(),m=0;
	rep(i,1,n)
	{
		int x=getint()&1;
		if(x) ++m;
	}
	if(f[n][m][0][0]) puts("Alice");
	else puts("Bob");
}

int main()
{
	int T=getint();
	init();
	while(T--) solve();
	return 0;
}