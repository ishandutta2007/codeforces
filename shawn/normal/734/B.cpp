#include <bits/stdc++.h>

using namespace std;

int read() {
	int x = 0 , f = 1 , c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1 , c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48 , c = getchar();
	return x * f;
}

long long k[5], ans;

int main() {
	for (int i = 1; i <= 4; i ++) k[i] = read();
	ans = min(k[1], min(k[3], k[4]));
	k[1] -= ans, k[3] -= ans, k[4] -= ans;
	ans *= 256;
	long long res = 0;
	res = min(k[2], k[1]);
	ans += res * 32;
	printf("%I64d\n", ans);
}