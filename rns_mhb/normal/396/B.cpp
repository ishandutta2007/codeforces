#include <stdio.h>
#include <memory.h>
#include <math.h>
typedef __int64 ll;
#define N 32000
int p[N],np;
bool mark[N];
void sieve_prime(){
	memset(mark,1,sizeof(mark));
	mark[0]=mark[1]=0;
	for (int i=2;i<=sqrt(N);i++) if (mark[i])
		for (int j=i*i;j<N;j+=i) mark[j]=0;
	for (int i=2;i<N;i++) if (mark[i]) p[np++]=i;
}
ll gcd(ll a,ll b){
	while (b) {ll c=a%b;a=b;b=c;}
	return a;
}
bool is_prime(int x) {
	for (int i=0;i<np && p[i]*p[i]<=x;i++) if (x%p[i]==0) return 0;
	return 1;
}
int main() {
	sieve_prime();
	int T,n,x,y;
	ll a,b,g;
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		for (x=n;!is_prime(x);x--);
		for (y=n+1;!is_prime(y);y++);
		a=n-x-y+1,b=ll(x)*y;
		a=b+a*2,b=b*2;
		g=gcd(a,b);
		a/=g,b/=g;
		printf("%I64d/%I64d\n",a,b);
	}
}