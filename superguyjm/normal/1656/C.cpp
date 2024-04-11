#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=200005;
typedef long long LL;
int n,a[N];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

bool check()
{
	sort(a+1,a+1+n);
	rep(i,2,n) if(a[i]-a[i-1]==1) return 0;
	return 1;
}

void solve()
{
	n=getint();
	int jdg=1;
	rep(i,1,n)
	{
		a[i]=getint();
		if(a[i]==1) jdg=0;
	}
	if(jdg) puts("YES");
	else
	{
		if(check()) puts("YES");
		else puts("NO");
	}
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}