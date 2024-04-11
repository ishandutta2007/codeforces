#include <bits/stdc++.h>
using namespace std;
#define mod 21

int n;

long long expmod(int a, int b) {
	long long rlt = 1, x = a;
	while (b) {
		if (b & 1) rlt = rlt * x % mod;
		x = x * x % mod, b >>= 1;
	}
	return rlt;
}

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d", &n);
	if (n <= 2) {
		puts("-1"); return 0;
	}
    if (n == 3) {
		printf("210\n"); return 0;
    }
    int x = expmod(10, n - 2), y = (21 - x) % mod;
    printf("1");
    for (int i = 2; i <= n - 3; i ++) printf("0");
    printf("%02d", y);
    printf("0\n");
	return 0;
}