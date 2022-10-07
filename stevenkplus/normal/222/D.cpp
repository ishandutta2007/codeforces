#include <cstdio>
#include <algorithm>

using namespace std;

const int inf = 1 << 30;
const int MAXN = 100100;

int a[MAXN], b[MAXN];
int N, M;

int main() {
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i) {
		scanf("%d", a + i);
	}
	for(int i = 0; i < N; ++i) {
		scanf("%d", b + i);
	}
	sort(a, a + N);
	sort(b, b + N);
	int m = inf;
	int x = 0;
	int y = N - 1;
	while (x < N && y >= 0) {
		int sum = a[x] + b[y];
		if (sum >= M) {
			m = min(m, sum);
			y--;
		} else {
			x++;
		}
	}
	x = 0;
	y = N - 1;
	int cnt = 0;
	while (x < N && y >= 0) {
		int sum = a[x] + b[y];
		if (sum >= m) {
			cnt++;
			x++;
			y--;
		} else {
			x++;
		}
	}
	printf("%d %d\n", 1, cnt);
	return 0;
}