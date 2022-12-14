#include <bits/stdc++.h>
using namespace std;

int a[11], n, cnt[11];

int main() {
	a[1] = 1;
	for (int k = 2; k <= 10; k ++) a[k] = a[k-1] * (k + 9) / (k - 1);
	scanf("%d", &n);
	for (int k = 10; k >= 1; k --) {
		while (n >= a[k]) {
			cnt[k] ++;
			n -= a[k];
		}
	}
    for (int k = 1; k <= 10; k ++) {
		for (int i = 0; i < 10; i ++) printf("%c", i + 'a');
		for (int i = 0; i < cnt[k]; i ++) printf("%c", 10 + 'a');
    }
    printf(" ");
    for (int i = 0; i <= 10; i ++) printf("%c", i + 'a');
	return 0;
}