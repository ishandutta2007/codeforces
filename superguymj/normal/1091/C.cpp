#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<cmath>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
int n;
LL pool[10000000];

void solve(LL x)
{
	++*pool;
	pool[*pool]=(1+n-x+1)*(n/x)/2;
}

int main()
{
	scanf("%d",&n);
	int P=sqrt(n);
	rep(i,1,P)
	{
		if(n%i==0) solve(i);
		if(n%i==0 && i*i!=n) solve(n/i);
	}
	sort(pool+1,pool+1+*pool);
	rep(i,1,*pool) printf("%lld ",pool[i]);
	puts("");
	return 0;
}