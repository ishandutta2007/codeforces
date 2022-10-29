#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=25;
int n,mx,a[N];

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
	n=getint(),mx=0;
	rep(i,1,n) a[i]=getint(),mx=max(mx,a[i]);
	rep(i,1,n) if(a[i]==mx)
	{
		printf("%d\n",i);
		break;
	}
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}