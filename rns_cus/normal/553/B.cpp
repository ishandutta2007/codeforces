#include <stdio.h>
#define N 99
long long c[N]={1,1,},k;
int n,a[N];
main() {
	for (int i=2;i<N;i++) c[i]=c[i-1]+c[i-2];
	scanf("%d%I64d",&n,&k);
	for (int i=1;i<=n;) {
		if (k>c[n-i]) {k-=c[n-i];a[i]=i+1;a[i+1]=i;i+=2;}
		else {a[i]=i;i++;}
	}
	for (int i=1;i<=n;i++) printf("%d ",a[i]);
}