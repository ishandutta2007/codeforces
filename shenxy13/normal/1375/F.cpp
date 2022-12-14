#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;
long long arr[4];
inline long long minv() {
	return min(arr[1], min(arr[2], arr[3]));
}
inline long long maxv() {
	return max(arr[1], max(arr[2], arr[3]));
}
inline long long medv() {
	return arr[1] + arr[2] + arr[3] - minv() - maxv();
}
int main() {
	int move;
	arr[0] = 0;
	for (int i = 1; i <= 3; ++i) scanf("%lld", &arr[i]);
	printf("First\n");
	fflush(stdout);
	while (maxv() - medv() > medv() - minv()) {
		printf("%lld\n", medv() - minv());
		fflush(stdout);
		scanf("%d", &move);
		arr[move] += medv() - minv();
		if (arr[move] == maxv()) goto hell;
	}
	printf("%lld\n", medv() - minv());
	fflush(stdout);
	scanf("%d", &move);
	arr[move] += medv() - minv();
	hell:;
	printf("%lld\n", 2 * maxv() - minv() - medv());
	fflush(stdout);
	scanf("%d", &move);
	arr[move] += 2 * maxv() - minv() - medv();
	printf("%lld\n", medv() - minv());
	fflush(stdout);
	scanf("%d", &move);
	assert(move == 0);
	return 0;
}