#include <stdio.h>
int main() {
	int n;
	long long k;
	int ans[50];
	scanf("%d%I64d", &n, &k);
	k--;
	int l=0, r = n-1;
	for (int i=0; i<n; i++) {
		if (!(k & (1ll<<n-2-i))) {
			ans[l] = i;
			l++;
		} else {
			ans[r] = i;
			r--;
		}
	}
	for (int i=0; i<n; i++) printf("%d%c", ans[i]+1, i == n-1 ? '\n' : ' ');
	return 0;
}