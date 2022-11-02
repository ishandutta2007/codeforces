#include <bits/stdc++.h>
using namespace std;
typedef long long INT;
INT mul(INT a, INT b, INT c) {
	return ((a*b-(INT)(a/(long double)c*b+1e-5)*c)%c+c)%c;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	INT a;
	scanf("%I64d",&a);
	INT r=45*18;
	INT s=100000000000000000LL%a;
	r=mul(r,s,a);
	printf("%I64d %I64d\n",a-r,a-r+999999999999999999LL);
	return 0;
}