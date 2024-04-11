#include <bits/stdc++.h>
using namespace std;

int n, d, m, len;

int main(){
//	freopen("b.in", "r", stdin);
	scanf("%d %d %d %d", &n, &d, &m, &len);
	for (int i = 1; i <= m; i ++) if (1ll * d * i <= 1ll * n * m ) {
		if (1ll * d * i % m > len) {
			printf("%I64d\n", 1ll * i * d); return 0;
		}
	}
	printf("%I64d\n", (1ll * n * m + d - 1) / d * d);
	return 0;
}