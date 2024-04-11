#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef long long INT;

#define MOD 1000000007

char a[110000];
INT power(INT u, INT v) {
	if (v==0) return 1;
	INT ret=power(u, v/2);
	ret=(ret*ret)%MOD;
	if (v&1) ret=(ret*u)%MOD;
	return ret;
}

int main() {
	
	int k, l, i, s;
	INT ret, tmp, x;
	
	scanf("%s", a);
	scanf("%d", &k);
	s=0; tmp=1;
	for (i=0; a[i]; i++) {
		if (a[i]=='0' || a[i]=='5') {
			s+=tmp;
			s%=MOD;
		}
		tmp=(tmp*2)%MOD;
	}
	if (!s) puts("0");
	else {
		l=strlen(a);
		ret=power(2, (INT)k*l)-1;
		x=power(2, l)-1;
		ret=(ret*power(x, MOD-2))%MOD;
		ret=(ret*s)%MOD;
		printf("%I64d\n", ret);
	}
	return 0;
}