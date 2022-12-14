#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	k = 240 - k;
	int i = 1;
	while (k >= i * 5) {
		k -= i * 5;
		i ++;
	}
	printf("%d\n", min(i - 1, n));
	return 0;
}