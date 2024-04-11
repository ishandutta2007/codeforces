#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=55;
int n,k,a[N];

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
	rep(i,1,n) if(a[i]) return 1;
	return 0;
}

void solve()
{
	n=getint(),k=getint();
	rep(i,1,n) a[i]=getint();
	if(check()) puts("YES");
	else puts("NO");
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}