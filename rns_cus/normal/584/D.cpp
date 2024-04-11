#include <bits/stdc++.h>
using namespace std;

#define N 1001001

int n, runs, p[N];
bool vis[N];

void get_prime() {
	for (int i = 2; i < N; i ++) {
		if (vis[i]) continue;
		p[++runs] = i;
		if (1ll * i * i >= N) continue;
		for (int j = i * i; j < N; j += i) vis[j] = 1;
	}
}

int expmod(int a, int b, int mod) {
	int rlt = 1, x = a;
	while (b) {
		if (b & 1) rlt = 1ll * rlt * x % mod;
		x = 1ll * x * x % mod, b >>= 1;
	}
	return rlt;
}

bool is_prime(int x) {
	if (x < N) return !vis[x];
	for (int i = 1; i <= 5; i ++) {
		if (expmod(2, x - 1, x) != 1) return 0;
	}
	return 1;
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d", &n);
	if (n == 3) {
		printf("1\n3\n"); return 0;
	}
    if (n == 5) {
		printf("1\n5\n"); return 0;
    }
    get_prime();
    if (n % 2 == 0) puts("2");
    else printf("3\n3 "), n -= 3;
    for (int i = 1; i <= runs; i ++) {
		if (is_prime(n - p[i])) {
			printf("%d %d\n", p[i], n - p[i]); return 0;
		}
    }
	return 0;
}