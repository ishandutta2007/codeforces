#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
typedef long long LL;
const int mod=1000000007;
LL n,k;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

LL phi(LL n)
{
	LL ret=1;
	for(LL i=2; i*i<=n; ++i) if(n%i==0)
	{
		ret*=(i-1),n/=i;
		while(n%i==0) ret*=i,n/=i;
	}
	if(n>1) ret*=(n-1);
	return ret;
}

int main()
{
	scanf("%lld%lld",&n,&k);
	k=(k+1)/2;
	while(k--)
	{
		n=phi(n);
		if(n==1) break;
	}
	printf("%lld\n",n%mod);
	return 0;
}