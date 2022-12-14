#include <bits/stdc++.h>
using namespace std;

int n, b[] = {0, 1, 2, 0, 3, 1, 2};
long long d[] = {4, 16, 82, 6724, 50626, 2562991876ll, 1ll << 60}, x;

int main() {
	scanf("%d", &n);
	int rlt = 0;
	while (n --) {
		scanf("%I64d", &x);
		for (int k = 0; k < 7; k ++) if (x < d[k]) {
			rlt ^= b[k];
			break;
		}
	}
	if (rlt) puts("Furlo");
	else puts("Rublo");
}