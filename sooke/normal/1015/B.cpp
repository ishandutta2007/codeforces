#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

#define SQR(x) ((x) * (x))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define LOWBIT(x) ((x) & -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define SWAP(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define MAXINT 2147483647
#define MAXLOL 9223372036854775807LL
#define INF MAXINT
#define lol long long
#define lod long double

inline char letter() {
	char c = getchar();
	while (c < 'a' || c > 'z') {
		c = getchar();
	}
	return c;
}
inline int read() {
	char c = getchar();
	int n = 0, f = 0;
	while (c < '0' || c > '9') {
		if (c == '-') {
			f = 1;
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		n = (n << 1) + (n << 3) + (c ^ 48);
		c = getchar();
	}
	return f ? -n : n;
}

#define MAXN 51

vector<int> V;
int n, a[MAXN], b[MAXN], cnta[MAXN], cntb[MAXN], mp[MAXN];
bool used[MAXN];

inline bool check() {
	for (int i = 1; i <= 26; i++) {
		if (cnta[i] != cntb[i]) {
			return true;
		}
	}
	return false;
}

int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = letter() - 'a' + 1;
		cnta[a[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		b[i] = letter() - 'a' + 1;
		cntb[b[i]]++;
	}
	if (check()) {
		printf("-1\n");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i] == b[j] && !used[j]) {
				used[j] = true;
				mp[i] = j;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mp[j] == i) {
				for (int k = j - 1; k >= i; k--) {
					SWAP(mp[k], mp[k + 1]);
					V.push_back(k);
				}
			}
		}
	}
	printf("%d\n", V.size());
	for (int i = 0; i < V.size(); i++) {
		printf("%d ", V[i]);
	}
	return 0;
}

// By Sooke.
// CF1015B Obtaining the String.