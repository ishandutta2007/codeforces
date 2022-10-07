#include <cstdio>
#include <algorithm>

using namespace std;

const int inf = 1 << 30;
const int MAXN = 100100;

int x[MAXN], y[MAXN];

int N;
int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%d %d", x + i, y + i);
	}
	int m = inf;
	int M = 0;
	for(int i = 0; i < N; ++i) {
		m = min (m, x[i]);
		M = max (M, y[i]);
	}
	int ans = -1;
	for(int i = 0; i < N; ++i) {
		if (x[i] == m && y[i] == M) {
			ans = i + 1;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}