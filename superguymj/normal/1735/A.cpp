#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
typedef long long LL;
int n;

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
	scanf("%d",&n),n-=3;
	int ans=0;
	int y=(n-1)/3;
	rep(i,y-100,y+100)
	{
		int a=1,b=i,c=n-i-1;
		if(a>0 && b>0 && c>0) ans=max(ans,min(min(abs(a-b),abs(b-c)),abs(a-c)));
	}
	printf("%d\n",ans);
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}