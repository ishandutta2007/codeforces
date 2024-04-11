#include<bits/stdc++.h>
using namespace std;

int  n, m;

int main() {
	scanf("%d%d", &n, &m);
	if (n > m) swap(n, m);
	if (n == 1) {
		printf("%d\n", 6 * (m / 6) + max(0, m % 6 - 3) * 2);
		return 0;
	}
	if (n == 2) {
		if (m == 2) puts("0");
		else cout<<2 * (m - (m == 3 || m == 7))<<endl;
	}
	else cout<<1ll * n * m - (m & n & 1)<<endl;
	return 0;
}