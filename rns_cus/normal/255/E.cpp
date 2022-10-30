#include <bits/stdc++.h>
using namespace std;
#define N 1001001

typedef long long LL;

int n, rlt;

LL nim(LL x) {
	if (x <= 3) return 0;
	if (x <= 15) return 1;
	if (x <= 81) return 2;
	if (x <= 6723) return 0;
	if (x <= 50625) return 3;
	if (x <= 2562991875ll) return 1;
	return 2;
}

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		LL x;
		scanf("%I64d", &x);
		rlt ^= nim(x);
	}
	if (rlt) puts("Furlo");
	else puts("Rublo");
	return 0;
}