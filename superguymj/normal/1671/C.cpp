#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=200005;
typedef long long LL;
int n,k,a[N];
LL ans;

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
	n=getint(),k=getint();
	int c=0;
	LL tot=0;
	rep(i,1,n) a[i]=getint();
	sort(a+1,a+1+n);
	rep(i,1,n) if(tot+a[i]<=k) c=i,tot+=a[i];
	ans=0;
	LL add=0;
	while(c)
	{
		if(add*c+tot>k) tot-=a[c],--c;
		else
		{
			LL p=(k-tot-add*c)/c;
			ans+=(p+1)*c;
			add+=p+1;
			tot-=a[c];
			--c;
		}
	}
	printf("%lld\n",ans);
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}