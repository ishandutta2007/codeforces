#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=1;i<=n;++i)
const int N=100005,P=1000000007;
ll f[N],g[N],rev[N],A,B,S;
int n,x,y,L,a[N];
ll C(ll n,ll m) {
	return m>n || m<0?0:f[n]*g[m]%P*g[n-m]%P;
}
int main() {
	scanf("%d",&n);
	rep(i,n) rev[i]=i==1?1:(-rev[P%i]*(P/i)%P);
	f[0]=g[0]=1;
	rep(i,n) f[i]=f[i-1]*i%P,g[i]=g[i-1]*rev[i]%P;
	rep(i,n) scanf("%d",&x),a[x]=i;
	x=0,y=1,L=0,A=0,B=1;
	rep(i,n) if (a[i]) {
		if (!x) x=a[i],y=x-i+1;
		else S=(A*C(L,x-a[i]-1)+B*C(L,y-a[i]-1))%P,B=(A*C(L,x-a[i]+i-1)+B*C(L,y-a[i]+i-1))%P,
			     A=S,x=a[i],y=x-i+1,L=0;
	} else if (x) ++L;
	else if (i>1) A=B=B*2%P;
	else A=B=1;
	printf("%I64d\n",((A*C(L,x-1)+B*C(L,y-1))%P+P)%P);
	return 0;
}