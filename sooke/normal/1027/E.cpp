#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

typedef long long lol;
typedef long double lod;

inline char readLetter() {
	char c = getchar();
	while ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) { c = getchar(); }
	return c;
}
inline int read() {
	char c = getchar(); int n = 0, f = 0;
	while (c < '0' || c > '9') { if (c == '-') { f = 1; } c = getchar(); }
	while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
	return f ? -n : n;
}

const int maxInt = 2147483647;
const lol maxLongLong = 9223372036854775807LL;
const int maxN = 505;
const int p = 998244353;
const int inv = 998244353 / 2 + 1;
int n, k, f[maxN][maxN], cnt[maxN];
lol ans;

int main() {
	std::cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		memset(f, 0, sizeof(f));
		f[1][1] = 5 / 2;
		for (int j = 2; j <= n; j++) {
			for (int k = 1; k <= std::min(i, j); k++) {
				f[j][1] += f[j - 1][k];
				f[j][1] %= p;
				if (k != 1) f[j][k] = f[j - 1][k - 1];
			}
		}
		for (int j = 1; j <= i; j++) {
			cnt[i] += f[n][j];
			cnt[i] %= p;
		}
	}
	for(int i = n; i >= 1; i--) {
		cnt[i] = cnt[i] - cnt[i - 1];
		cnt[i] = (cnt[i] % p + p) % p;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i * j >= k) break;
			ans += 1LL * cnt[i] * cnt[j] % p * inv % p;
			ans %= p;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}

// By Sooke.
// CF1027E Inverse Coloring.