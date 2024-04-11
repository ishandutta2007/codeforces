#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=100005;
int n,k,a[N],ans;

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
	rep(i,1,n) a[i]=getint()+a[i-1];
	ans=n;
	rep(i,0,n)
		ans=min(ans,max(a[i],n-i-a[n]+a[i]));
	printf("%d\n",ans);
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}