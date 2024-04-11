#include <stdio.h>

int func(int a) {
	if (a == 1) return 2;
	if (a == 2) return 1;
	return a;
}

#define N 110

int n, a[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= n;) {
		if (a[i] == 3) {
			n --;
			for (int j = i; j <= n; j ++) a[j] = func(a[j+1]);
		}
		else i ++;
	}
	int rlt = 0;
	for (int i = 1; i <= n;) {
		if (a[i] == 0) rlt ++, i ++;
		else {
			int j = i + 1;
			for (j = i + 1; j <= n && a[j] == a[i]; j ++);
			rlt += (j - i) / 2;
			i = j;
		}
	}
	printf("%d\n", rlt);
	return 0;
}