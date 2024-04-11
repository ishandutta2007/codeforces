#include <cstdio>
#include <queue>
#include <tuple>

using namespace std;

int a[100001];
long long d[22][100001];
long long tt;
int b[100001];
int L, R;

inline void add(int x) {
	tt += b[x];
	b[x]++;
}

inline void sub(int x) {
	b[x]--;
	tt -= b[x];
}

inline void moveL(int tL) {
	while (L < tL) sub(a[++L]);
	while (L > tL) add(a[L--]);
}

inline void moveR(int tR) {
	while (R < tR) add(a[++R]);
	while (R > tR) sub(a[R--]);
}

int main() {
	queue<tuple<int, int, int, int> > q;
	int i, j, k, n, m;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		d[0][i] = 1e18;
	}
	for (i = 1; i <= m; i++) {
		q.emplace(1, n, 0, n - 1);
		while (!q.empty()) {
			int S, E, L, R, M;
			tie(S, E, L, R) = q.front();
			q.pop();
			if (S > E) continue;
			M = S + E >> 1;
			moveR(M);
			d[i][M] = 1e18;
			for (j = k = L; j <= R && j < M; j++) {
				moveL(j);
				long long t = d[i - 1][j] + tt;
				if (t < d[i][M]) {
					d[i][M] = t;
					k = j;
				}
			}
			q.emplace(S, M - 1, L, k);
			q.emplace(M + 1, E, k, R);
		}
	}
	printf("%lld\n", d[m][n]);
	return 0;
}