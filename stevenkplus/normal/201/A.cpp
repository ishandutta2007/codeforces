#include <cstdio>

using namespace std;

int f(int x) {
	int k = x / 2;
	return k * x + ((x + 1) / 2);
}

int solve(int N) {
	if (N == 3) return 5;
	int i;
	for(i = 1; f(i) < N; i += 2);
	return i;
}

int main() {
	int N;
	scanf("%d", &N);

	int ans = solve(N);
	printf("%d\n", ans);
	return 0;
}