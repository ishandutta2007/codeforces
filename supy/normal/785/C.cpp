#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#define MAXN 20005
#define MAXM 200050
#define INF 0x7f7f7f7f
#define ll long long
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define clr(x) memset(x,0,sizeof(x));
using namespace std;

inline void read(int &x) {
	x=0; int f=1; char c=getchar();
	while (c<'0'||c>'9'){if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9'){x=10*x+c-'0'; c=getchar();} x*=f;
}
int main()
{
	ll n,m;
	scanf("%lld%lld",&n,&m);
	if (m>=n) {printf("%lld",n); return 0;}
	ll l=0, r=1e10; //!!
	while (l<r) {
		ll mid=(l+r)>>1;
		if (n-m-(ll)(mid+1)*(mid+2)/2<=0) r=mid;
		else l=mid+1;
	}
	printf("%lld\n",l+1+m);
	return 0;
}