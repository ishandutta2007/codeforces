#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

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

#define MAXN 3005

vector< pair<int, int> > vc[MAXN];
int n, m, cnt;
bool used[MAXN];
lol ans = MAXLOL, res;

struct Person {
	int id, k;
} p[MAXN];

bool cmp(Person a, Person b) {
	return a.k < b.k;
}

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		int u = read(), w = read();
		p[i] = (Person) {i, w};
		vc[u].push_back(make_pair(w, i));
	}
	sort(p + 1, p + n + 1, cmp);
	for (int i = 1; i <= m; i++) {
		sort(vc[i].begin(), vc[i].end());
	}
	for (int i = 0; i <= n; i++) {
		res = 0;
		memset(used, false, sizeof(used));
		cnt = 0;
		if (vc[1].size() > 0)
			for (int j = 0; j <= vc[1].size() - 1; j++) {
				cnt++;
				used[vc[1][j].second] = true;
			}
		for (int j = 2; j <= m; j++) {
			if (vc[j].size() > i) {
				for (int k = 0; k <= vc[j].size() - i - 1; k++) {
					cnt++;
					res += vc[j][k].first;
					used[vc[j][k].second] = true;
				}
			}
		}
		if (cnt <= i) {
			for (int j = 1; j <= n; j++) {
				if (!used[p[j].id]) {
					cnt++;
					res += p[j].k;
				}
				if (cnt > i) {
					break;
				}
			}
		}
		ans = MIN(ans, res);
	}
	printf("%I64d\n", ans);
	return 0;
}

// By Sooke.
// CF1019A Elections.