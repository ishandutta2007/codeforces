#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=105;
bool vis[N];
int n,a[N];

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
	if(n&1)
	{
		int tot=0;
		rep(i,1,n) vis[i]=0;
		vis[1]=vis[n-2]=vis[n]=1;
		rep(i,1,n) if(!vis[i]) a[++tot]=i;
		a[n-2]=1,a[n-1]=n-2,a[n]=n;
		for(int i=1; i<=n-3; i+=2)
			swap(a[i],a[i+1]);
	}
	else
	{
		rep(i,1,n) a[i]=i;
		for(int i=1; i<=n-2; i+=2)
			swap(a[i],a[i+1]);
	}
	rep(i,1,n) printf("%d ",a[i]);
	puts("");
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}