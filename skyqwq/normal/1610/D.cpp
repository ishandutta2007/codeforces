// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5, P = 1e9 + 7;

int n, a[N], f[2][2], g[2][2], ans, A[N], B[N];
 
int inline get(int x) {
	int c = 0;
	while (x % 2 == 0) c++, x /= 2;
	return c;
}

void inline add(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}

int main() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]), A[i] = get(a[i]), B[i] = get(a[i] - 1);
	for (int i = 0; i < 30; i++) {
		memset(f, 0, sizeof f);
		f[0][0] = 1;
		for (int j = 1; j <= n; j++) {
			int x = A[j], y = B[j];
			if (x < i) continue;
			memcpy(g, f, sizeof g);
			if (x + y - i - 1 >= 0) {
				for (int u = 0; u < 2; u++) {
					for (int v = 0; v < 2; v++) {
						add(f[u | (x == i)][v], g[u][v]);
					}
				}
			} else {
				for (int u = 0; u < 2; u++) {
					for (int v = 0; v < 2; v++) {
						add(f[u | (x == i)][v ^ 1], g[u][v]);
					}
				}
			}
		}
		(ans += f[1][0]) %= P;
	}
	printf("%d\n", ans);
    return 0;
}