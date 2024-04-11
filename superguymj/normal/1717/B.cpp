#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int n,k,r,c;
bool f[505][505];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void solve()
{
	n=getint(),k=getint(),r=getint(),c=getint();
	rep(i,1,n) rep(j,1,n) f[i][j]=0;
	rep(i,1,n/k)
	{
		while(!f[r][c])
		{
			f[r][c]=1;
			++r,--c;
			if(r==n+1) r=1;
			if(c==0) c=n;
		}
		c+=k;
		if(c>n) c-=n;
	}
	rep(i,1,n)
	{
		rep(j,1,n)
		{
			if(f[i][j]==0) putchar('.');
			else putchar('X');
		}
		puts("");
	}
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}