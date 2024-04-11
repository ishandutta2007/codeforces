#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

#define Maxn 5001
#define Maxc 10001

#define Max(x, y) ((x) > (y) ? (x) : (y))

map<int, int> M;
int n, cnt, a[Maxn], ans[Maxn];
int m, k, b[Maxn];
bool vis[Maxc], used[Maxn];

void init() {
	for (int i = 2; i < Maxc; i++) {
		if (!vis[i]) {
			for (int j = i + i; j < Maxc; j += i) {
				vis[j] = true;
			}
			b[++m] = i * i;
		} 
	}
}

int main() {
	init();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] != 0) {
			bool minus = a[i] < 0;
			if (minus) {
				a[i] = -a[i];
			}
			for (int j = 1; j <= m && b[j] <= a[i]; j++) {
				while (a[i] % b[j] == 0) {
					a[i] /= b[j];
				}
			}
			if (minus) {
				a[i] = -a[i];
			}
			int t = M[a[i]];
			if (t == 0) {
				M[a[i]] = ++k; 
				a[i] = k;
			} else {
				a[i] = t;
			}
		} else {
			a[i] = 0;	
		}
	}
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		memset(used, false, sizeof(used));
		for (int j = i; j <= n; j++) {
			if (used[a[j]] == false && a[j] != 0) {
				cnt++;
				used[a[j]] = true;
			}
			ans[Max(cnt, 1)]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d", ans[i]);
		if (i == n) {
			printf("\n");
		} else {
			printf(" ");
		}
	}
	return 0;
}

// By Sooke.
// CF980D Perfect Groups.