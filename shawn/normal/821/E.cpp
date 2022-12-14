#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

long long rd() {
	long long x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

const int P = 1e9 + 7;
struct Martix {
	int a[17][17];
	Martix() { memset(a, 0, sizeof a); }
}ans;
long long n, K;
bool fg;

void Add(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}

Martix mul(Martix A, Martix B, int C) {
	Martix re;
	for (int k = 0; k <= C; k ++) 
		for (int i = 0; i <= C; i ++) 
			for (int j = 0; j <= C; j ++) 
				if (A.a[i][k] && B.a[k][j]) Add(re.a[i][j], 1ll * A.a[i][k] * B.a[k][j] % P);
	return re;
}

void power(long long B, int C) {
	Martix e;
	for (int i = 0; i < 16; i ++) {
		e.a[i][i] = 1;
		if (i) e.a[i][i - 1] = 1;
		if (i + 1 < 16) e.a[i][i + 1] = 1;
	}
	for (int i = C + 1; i < 16; i ++) ans.a[i][0] = 0;
	for (; B; B >>= 1, e = mul(e, e, C)) if (B & 1) ans = mul(ans, e, C);
}

int main() {
	n = rd(), K = rd();
	ans.a[0][0] = 1;
	for (int i = 0; i < n; i ++) {
		long long a = rd() + 1, b = rd(), c = rd();
		if (K < b) b = K, fg = 1;
		power(b - a + 1, c);
		if (fg) break;
	}
	printf("%d\n", ans.a[0][0]);
	return 0;
}