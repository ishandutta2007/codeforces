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

vector<lol> V;
lol n, m, s, used, cur = 1;
bool flag = true;

int main() {
	std::cin >> n >> m >> s;
	if (s < m || s > m * (n - 1)) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	V.push_back(1);
	while (true) {
		used++;
		if (s <= n - 1) {
			if (flag) {
				V.push_back(cur + s);
				cur += s;
			} else {
				V.push_back(cur - s);
				cur -= s;
			}
			break;
		} else {
			if (flag) {
				V.push_back(cur + n - 1);
				cur += n - 1;
			} else {
				V.push_back(cur - n + 1);
				cur -= n - 1;
			}
			s -= n - 1;
		}
		flag = !flag;
	}
	for (int i = 1; i < V.size(); i++) {
		if (used < m) {
			for (lol j = V[i - 1] + 1; j < V[i]; j++) {
				printf("%I64d ", j);
				used++;
				if (used == m) {
					break;
				}
			}
			for (lol j = V[i - 1] - 1; j > V[i]; j--) {
				printf("%I64d ", j);
				used++;
				if (used == m) {
					break;
				}
			}
		}
		printf("%I64d ", V[i]);
	}
	return 0;
}

// By Sooke.
// CF1015D Walking Between Houses.