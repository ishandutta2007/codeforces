#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
 
LL a, b, c;
 
// ax + by = d
LL exgcd(LL a, LL b, LL &x, LL &y) {
    //printf("exgcd %lld %lld\n",a,b);
	if (!b) {
		x = 1;
		y = 0;
		return a;
	} else {
		LL ret = exgcd(b, a % b, x, y);
		LL tmp = x;
		x = y;
		y = tmp - (a / b) * y;
		return ret;
	}
}
 
void merge(LL x, LL y) {
    //printf("merge %lld %lld\n",x,y);
	if (y == 0) {
		c = __gcd(c, x);
		return;
	}
	// y != 0
	if (a == 0 && b == 0) {
		a = x;
		b = y;
		return;
	}
	// (a, b) != (0, 0)
	LL x1 = y;
	LL x2 = b;
    //printf("%lld %lld\n",a,b);
    //printf("%lld %lld\n",x1,x2);
	LL g = __gcd(x1, x2);
	x1 /= g;
	x2 /= g;
    //printf("%lld\n",g); 
	LL K = abs(a * x1 - x * x2);
	c = __gcd(c, K);
	LL d = exgcd(b, y, x1, x2);
    //printf("%lld %lld %lld %lld\n",c,K,x1,x2);
	b = d;
	a = a * x1 + x * x2;
    if (c) a %= c;
}
 
int main() {
	int T = 1;
	for (int _=1;_<=T;_++) {
        int N;
        int dx1, dx2, dy1, dy2;
        scanf("%d",&N);
        scanf("%d%d%d%d",&dx1,&dy1,&dx2,&dy2);
		a = 0;
		b = 0;
		c = 0;
        merge(dx1, dy1);
        merge(dx2, dy2);
        //printf("%d %d %d\n",a,b,c);
        if (1LL * abs(b) * abs(c) == N) {
            puts("YES");
            for (int i=0;i<abs(b);i++) {
                for (int j=0;j<abs(c);j++) {
                    printf("%d %d\n",j,i);
                }
            }
        } else {
            puts("NO");
        }
	}
}