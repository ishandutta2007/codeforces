#include <cstdio>

int n;
int a[30];

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int main(){
	scanf("%d", &n);
	int d = 0, cnt = 0;
	for (int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		d = gcd(d, a[i]);
		cnt += a[i] & 1;
	}
	if (cnt == 0){
		printf("%d\n", d);
		for (int k = 0; k < d; ++k)
			if (k & 1){
				for (int i = 0; i < n; ++i)
					for (int j = a[i] / d; j; --j)
						putchar('a' + i);
			}
			else{
				for (int i = n - 1; i >= 0; --i)
					for (int j = a[i] / d; j; --j)
						putchar('a' + i);
			}
	}
	else if (cnt == 1){
		printf("%d\n", d);
		for (int k = 0; k < d; ++k){
			for (int i = 0; i < n; ++i)
				if (!(a[i] & 1))
					for (int j = a[i] / d / 2; j; --j)
						putchar('a' + i);
			for (int i = 0; i < n; ++i)
				if (a[i] & 1)
					for (int j = a[i] / d; j; --j)
						putchar('a' + i);
			for (int i = n - 1; i >= 0; --i)
				if (!(a[i] & 1))
					for (int j = a[i] / d / 2; j; --j)
						putchar('a' + i);
		}
	}
	else{
		printf("%d\n", 0);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < a[i]; ++j)
				putchar('a' + i);
	}
	puts("");
	return 0;
}