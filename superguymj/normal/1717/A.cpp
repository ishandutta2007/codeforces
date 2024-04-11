#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;

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
	int n=getint();
	printf("%d\n",n+(n/2+n/3)*2);
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}