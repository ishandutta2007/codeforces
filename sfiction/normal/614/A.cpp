#include <cstdio>

typedef long long ll;

int main(){
	ll l, r, k;
	scanf("%I64d%I64d%I64d", &l, &r, &k);
	bool flag = false;
	for (ll i = 1;; i *= k){
		if (l <= i){
			if (flag)
				putchar(' ');
			flag = true;
			printf("%I64d", i);
		}
		if (i > r / k)
			break;
	}
	puts(flag ? "" : "-1");
	return 0;
}