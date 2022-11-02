#include <stdio.h>

typedef __int64 ll;

int main() {
	int a, b, d, n, q, r, D=0, Q, R, cnt, i, j;
	ll ans, tmp;
//	freopen ("in.txt", "r", stdin);
	scanf("%d %d", &a, &b);
	ans=1LL*a*a-1LL*b*b;
	for (d=1; d<=a && d<b; d++) {
		tmp=1LL*(a-d+1)*(a-d+1)+d-1;
		q=b/(d+1), r=b%(d+1);
		tmp-=1LL*r*(q+1)*(q+1)+1LL*(d+1-r)*q*q;
		if (ans<tmp) ans=tmp, D=d, Q=q, R=r;
	}
	printf("%I64d\n", ans);
	if (!D) {
		for (i=0; i<a; i++) putchar('o');
		for (i=0; i<b; i++) putchar('x');
	} else {
		cnt=0;
		for (i=1; i<=2*D+1; i++) {
			if (i&1) {
				for (j=0; j<Q; j++) putchar('x');
				cnt++;
				if (cnt<=R) putchar('x');
			} else {
				if (i==2) for (j=0; j<a-D+1; j++) putchar('o');
				else putchar('o');
			}
		}
	}
	puts("");
}