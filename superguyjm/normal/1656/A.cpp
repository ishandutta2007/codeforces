#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=100005;
int n,a[N];
typedef long long LL;

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

void solve()
{
	n=getint();
	int mn=1000000000,mx=0;
	rep(i,1,n) a[i]=getint(),mn=min(mn,a[i]),mx=max(mx,a[i]);
	int x=0,y=0;
	rep(i,1,n)
	{
		if(mn==a[i]) x=i;
		if(mx==a[i]) y=i;
	}
	printf("%d %d\n",x,y);
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}