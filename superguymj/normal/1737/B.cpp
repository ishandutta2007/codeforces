#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid ((l+r)>>1)

using namespace std;
typedef long long LL;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

LL get(LL x)
{
	if(!x) return 0;
	LL p=sqrt(x)-1;
	while((p+1)*(p+1)<=x) ++p;
	LL ret=(p-1)*3;
	LL nw=p*p;
	rep(i,0,2) if(nw+i*p<=x) ++ret;
	return ret;
}

void solve()
{
	LL l,r;
	scanf("%lld%lld",&l,&r);
	printf("%lld\n",get(r)-get(l-1));
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}