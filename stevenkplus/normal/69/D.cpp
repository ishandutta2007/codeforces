#include <cstdio>

using namespace std;

const int SIZE = 401;
const int ORIG = 200;
const int MAXN = 21;

int X, Y, N, D;

int mx[MAXN];
int my[MAXN];

int dp[SIZE][SIZE];

bool far(int x, int y) {
	int dx = x - ORIG;
	int dy = y - ORIG;
	return dx * dx + dy * dy > D * D;
}

int get(int x, int y) {
	if (far(x, y)) return 1;
	int &ret = dp[x][y];
	if (ret) return ret - 1;

	for(int i = 0; i < N; ++i) {
		int nx = x + mx[i];
		int ny = y + my[i];
		if (!get(nx, ny)) {
			ret = 1;
			break;
		}
	}

	return ret++;
}

int main() {
	scanf("%d %d %d %d", &X, &Y, &N, &D);
	for(int i = 0; i < N; ++i) {
		scanf("%d %d", mx + i, my + i);
	}

	int ans = get(X + ORIG, Y + ORIG);
	if (ans) {
		printf("Anton\n");
	} else {
		printf("Dasha\n");
	}
	return 0;
}