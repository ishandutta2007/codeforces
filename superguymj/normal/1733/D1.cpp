#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=5005;
int n,x,y;
int m,p[N];
char s[N];
int a[N];

void solve()
{
	scanf("%d%d%d",&n,&x,&y);
	scanf("%s",s+1);
	rep(i,1,n) a[i]=s[i]-'0';
	scanf("%s",s+1);
	rep(i,1,n) a[i]^=(s[i]-'0');
	m=0;
	rep(i,1,n) if(a[i]) p[++m]=i;
	if(m&1)
	{
		puts("-1");
		return;
	}
	if(!m)
	{
		puts("0");
		return;
	}
	if(x>=y)
	{
		if(m>2 || p[1]+1<p[2]) printf("%lld\n",(LL)y*m/2);
		else printf("%d\n",min(y*2,x));
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}