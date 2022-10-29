#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
typedef long long LL;
int n;
int a[105];

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
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	int x=a[1],y=2*x-1;
	int ans=1;
	rep(i,2,n)
		ans+=(a[i]+y-1)/y;
	printf("%d\n",ans-n);
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}