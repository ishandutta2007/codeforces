#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=200005;
int n,a[N],b[N];

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
	n=getint();
	rep(i,1,n) a[i]=getint();
	rep(i,1,n) b[i]=getint();
	rep(i,1,n) if(a[i]>b[i])
	{
		puts("No");
		return;
	}
	b[n+1]=b[1];
	rep(i,1,n) if(b[i]>b[i+1]+1 && a[i]!=b[i])
	{
		puts("No");
		return;
	}
	puts("Yes");
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}