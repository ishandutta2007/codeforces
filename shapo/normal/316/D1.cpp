#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;

#define maxn 15

int c[maxn];
int n;
int ans;
bool used[maxn];
bool ok[maxn];
int nxt[maxn];

void check() {
	memset(ok, 0, sizeof(bool) * (n + 1));
	for (int i = 1; i <= n; ++i) {
		if (!ok[i]) {
			ok[i] = true;
			int cur = i, cnt = 0;
			if (c[cur] == 1) ++cnt;
			while (!ok[nxt[cur]]) {
				cur = nxt[cur];
				ok[cur] = true;
				if (c[cur] == 1) ++cnt;
			}
			if (cnt > 2) return;
		}
	}
	++ans;
}

int gen(int x) {
	if (x == n) {
		check();
		return 0;
	}
	for (int i = 1; i <= n; ++i)
		if (!used[i]) {
			used[i] = true;
			nxt[x + 1] = i;
			gen(x + 1);
			used[i] = false;
		}
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", c + i);
	gen(0);
	printf("%d\n", ans);
	return 0;
}