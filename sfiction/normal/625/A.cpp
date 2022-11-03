#include <cstdio>

int main(){
	long long n, a, b, c;
	scanf("%I64d%I64d%I64d%I64d", &n, &a, &b, &c);
	if (a <= b - c)
		printf("%I64d\n", n / a);
	else{
		long long t = (n - c) / (b - c);
		if (t < 0)
			t = 0;
		printf("%I64d\n", t + (n - t * (b - c)) / a);
	}
	return 0;
}