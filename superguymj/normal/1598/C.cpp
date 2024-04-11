#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=200005;
int n,a[N];
LL s,ans;
map <LL,LL> mp;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;	
	return x;
}

LL gcd(LL a,LL b)
{
	return !b?a:gcd(b,a%b);
}

void solve()
{
	n=getint(),s=0;
	rep(i,1,n) s+=(a[i]=getint());
	LL d=gcd(s,n),x=n;
	s/=d,x/=d;
	if(x==1) x*=2,s*=2;
	if(x!=2) {puts("0"); return;}
	mp.clear(),ans=0;
	rep(i,1,n)
		ans+=mp[s-a[i]],++mp[a[i]];
	printf("%lld\n",ans);
}

int main()
{
//	freopen("c.in","r",stdin);
	int T=getint();
	while(T--)
		solve();
	return 0;
}