#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <queue>

using namespace std;

#define maxn 1000500

int n, m;
int a[maxn];
int b[maxn], pk[maxn];
int cur[30];
int nxt[30], prev[30];

bool ok(const int &cnt) {
	memset(cur, 0, sizeof(cur));
	memset(nxt, -1, sizeof(nxt));
	memset(prev, -1, sizeof(prev));
	for (int i = cnt - 1; i >= 0; --i)
		++cur[pk[i]];
	int maxCur = -1;
	for (int i = 0; i < 30; ++i)
		if (cur[i] != 0) {
			int nextCur = i + 1;
			while (nextCur < 30 && !cur[nextCur]) ++nextCur;
			if (nextCur < 30) {
				prev[nextCur] = i, nxt[i] = nextCur;
			}
			maxCur = i;
		}
	for (int i = 0; i < n; ++i) {
		int pos = maxCur, now = a[i];
		while (pos != -1) {
			while (cur[pos] && (1 << pos <= now)) {
				--cur[pos];
				now -= (1 << pos);
			}
			if (cur[pos] == 0) {
				if (nxt[pos] != -1 && prev[pos] != -1) nxt[prev[pos]] = nxt[pos], prev[nxt[pos]] = prev[pos];
				else if (nxt[pos] == -1) maxCur = prev[pos], nxt[prev[pos]] = -1;
				else prev[nxt[pos]] = -1;
			}
			pos = prev[pos];
		}
	}
	for (int i = 0; i < 30; ++i)
		if (cur[i]) return false;
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int j = 0; j < m; ++j)
		scanf("%d", b + j), b[j] = (1 << b[j]);
	sort(b, b + m);
	for (int i = 0; i < m; ++i)
		while ((1 << pk[i]) != b[i]) ++pk[i];
	int l = 0, r = m + 1;
	while (l < r - 1) {
		int tmp = (l + r) / 2;
		if (ok(tmp)) l = tmp; else r = tmp;
	}
	printf("%d\n", l);
	return 0;
}