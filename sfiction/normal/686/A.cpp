#include <cstdio>

typedef long long ll;

int main(){
	int n;
	ll x;
	scanf("%d%I64d%*c", &n, &x);
	int s = 0;
	for (int i = 0; i < n; ++i){
		char chr;
		int t;
		scanf("%c%d%*c", &chr, &t);
		if (chr == '+')
			x += t;
		else{
			if (x >= t)
				x -= t;
			else
				++s;
		}
	}
	printf("%I64d %d\n", x, s);
	return 0;
}