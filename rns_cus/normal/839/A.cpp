#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, k, x, rem;

int main() {
	///freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i ++) {

		scanf("%d", &x);
		rem += x;
		x = min(rem, 8);
		if (x >= k) { cout << i << endl; return 0; }
		k -= x;
		rem -= x;
	}
	puts("-1");
}