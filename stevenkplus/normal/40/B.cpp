#include <cstdio>

using namespace std;

int N, M;
int X;

int get(int a, int b) {
	if (a < 0 || b < 0) return 0;
	int x = a / 2, y = b / 2;
	return x * y + (a - x) * (b - y);
}

int main() {
	scanf("%d %d", &N, &M);
	scanf("%d", &X);

	N -= 2 * (X - 1);
	M -= 2 * (X - 1);

	int cur = get(N, M);
	int nxt = get(N - 2, M - 2);
	int ans = cur - nxt;

	printf("%d\n", ans);
	return 0;
}