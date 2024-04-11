#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	int a = 0, b = 0;
	for(int i = 0; i < N; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		a += x;
		b += y;
	}
	int sum = min(a, N - a) + min(b, N - b);
	printf("%d\n", sum);
	return 0;
}