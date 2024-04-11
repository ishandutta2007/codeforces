#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=200005;
typedef long long LL;
int n,m;
char s[N];
int a[N];
LL ans;

bool check()
{
	rep(i,1,m) if(a[i]!=1) return 0;
	return 1;
}

void solve()
{
	scanf("%d",&n);
	scanf("%s",s+1),m=strlen(s+1);
	rep(i,1,m) a[i]=(s[i]==s[1]);
	if(check())
	{
		printf("%d\n",n);
		return;
	}
	ans=(LL)n*n;
	int x;
	rep(i,1,m) if(a[i]==1) ans-=n-1; else {x=i; break;}
	int nw=0;
	repd(i,m,x) if(!a[i]) ++nw; else ans-=nw;
	nw=0;
	repd(i,m,1) if(!a[i]) ans-=nw; else ++nw;
	printf("%lld\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	rep(i,1,t) solve();
	return 0;
}