#include <cstdio>

using namespace std;

const int MAXN = 110;
const int inf = 1 << 30;

int d[MAXN][MAXN];
int ar[MAXN];

int X[MAXN], Y[MAXN];

int N, D;
int calc(int a, int b) {
	int dx = X[a] - X[b];
	int dy = Y[a] - Y[b];
	int sum = 0;
	if (dx > 0) sum += dx;
	else sum -= dx;

	if (dy > 0) sum += dy;
	else sum -= dy;
	return sum;
}

int dist[MAXN];
bool vis[MAXN];

void dijk() {
	for(int i = 0; i < N; ++i) {
		dist[i] = inf;
	}
	dist[0] = 0;

	while (!vis[N - 1]) {
		int best = -1;
		for(int i = 0; i < N; ++i) {
			if (!vis[i] && (best == -1 || dist[i] < dist[best])) {
				best = i;
			}
		}

		vis[best] = true;
		for(int j = 0; j < N; ++j) {
			if (vis[j]) continue;
			int newd = dist[best] + d[best][j] - ar[j];
			if (newd < dist[j]) dist[j] = newd;
		}
	}
}


int main() {
	scanf("%d %d", &N, &D);

	for(int i = 1; i < N - 1; ++i) {
		scanf("%d", ar + i);
	}

	for(int i = 0; i < N; ++i) {
		scanf("%d %d", X + i, Y + i);
	}

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			d[i][j] = D * calc(i, j);
		}
	}

	dijk();
	int ans = dist[N - 1];
	printf("%d\n", ans);
	return 0;
}