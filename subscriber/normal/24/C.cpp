#include <stdio.h>

int n;

long long o,xx,yy,x[200000],y[200000];

int main(){
	scanf("%d%I64lld",&n,&o);
	scanf("%I64lld%I64lld",&xx,&yy);
	for (int i=0;i<n;i++)scanf("%I64lld%I64lld",&x[i],&y[i]);
	o%=n+n;
	for (int i=1;i<=o;i++){
		xx+=2*(x[(i-1)%n]-xx);
		yy+=2*(y[(i-1)%n]-yy);
	}
	printf("%I64lld %I64lld\n",xx,yy);
	return 0;
}