#include <stdio.h>
#include <string.h>
char i1[1000010], i2[1000010];
int main() {
	int n;
	scanf("%d%s%s", &n, i1, i2);
	int l, r;
	for (int i=0; i<n; i++) {
		if (i1[i] != i2[i]) {l = i; break;}
	}
	for (int j=n-1; j>=0; j--) {
		if (i1[j] != i2[j]) {r = j; break;}
	}
	int ans = 0;
	for (int i=l; i<=r; i++) {
		if (i==r) ans++;
		if (i1[i] != i2[i+1]) break;
	}
	for (int i=l; i<=r; i++) {
		if (i==r) ans++;
		if (i1[i+1] != i2[i]) break;
	}
	printf("%d\n", ans);
	return 0;
}