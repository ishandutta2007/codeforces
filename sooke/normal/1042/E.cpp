#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

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
const lol maxLongLong = 9223372036854775807ll;
const int maxN = 1005, p = 998244353;

std::vector<int> vx[maxN * maxN], vy[maxN * maxN];
int n, m, unin, r, c, sum, table[maxN * maxN], a[maxN][maxN], f[maxN][maxN]; 
int inv[maxN * maxN], cnt, sumx2, sumy2, sumx, sumy;

void insert(int x, int y) {
	cnt++;
	sum = (sum + f[x][y]) % p;
	sumx = (x + sumx) % p, sumy = (y + sumy) % p;
	sumx2 = (1ll * x * x + sumx2) % p, sumy2 = (1ll * y * y + sumy2) % p;
}

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) { table[++unin] = a[i][j] = read(); }
	}
	r = read(), c = read();
	std::sort(table + 1, table + unin + 1);
	unin = std::unique(table + 1, table + unin + 1) - table - 1;
	inv[1] = 1;
	for (int i = 2; i <= n * m; i++) { inv[i] = 1ll * (p - p / i) * inv[p % i] % p; }
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			a[i][j] = std::lower_bound(table + 1, table + unin + 1, a[i][j]) - table;
			vx[a[i][j]].push_back(i), vy[a[i][j]].push_back(j);
		}
	}
	for (int i = 0; i < (int)vx[1].size(); i++) {
		int x = vx[1][i], y = vy[1][i];
		insert(x, y);
	}
	for (int i = 2; i <= unin; i++) {
		for (int j = 0; j < (int)vx[i].size(); j++) {
			int x = vx[i][j], y = vy[i][j];
			f[x][y] = ((1ll * sum + sumx2 + sumy2 + 1ll * x * x % p * cnt + 1ll * y * y % p * cnt - 2ll * x * sumx - 2ll * y * sumy) % p + p) % p * inv[cnt] % p;
		}
		for (int j = 0; j < (int)vx[i].size(); j++) {
			int x = vx[i][j], y = vy[i][j];
			insert(x, y);	
		}
	}
	std::cout << f[r][c] << std::endl;
	return 0;
}