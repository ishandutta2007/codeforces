#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=55;
int n,m,a[N][N];
char s[N][N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

bool check(int x)
{
	rep(i,1,n) rep(j,1,m) if(a[i][j]>-1)
		if(a[i][j]!=((i^j^x)&1)) return 0;
	return 1;
}

void PRT(int x)
{
	rep(i,1,n) 
	{
		rep(j,1,m)
		{
			int t=(i^j^x)&1;
			if(t) putchar('R');
			else putchar('W');
		}
		puts("");
	}
}

void solve()
{
	n=getint(),m=getint();
	rep(i,1,n) scanf("%s",s[i]+1);
	rep(i,1,n) rep(j,1,m)
	{
		if(s[i][j]!='.') a[i][j]=(s[i][j]=='R');
		else a[i][j]=-1;
	}
	if(check(0))
		puts("YES"),PRT(0);
	else if(check(1)) puts("YES"),PRT(1);
	else puts("NO");
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}