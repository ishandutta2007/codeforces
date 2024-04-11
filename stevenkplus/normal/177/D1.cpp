#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100100;
int a[MAXN];
int b[MAXN];
int sums[MAXN];

int main() {
	int N,M,C;
	scanf("%d %d %d",&N,&M,&C);
	for(int i = 0; i < N; ++i) {
		scanf("%d", a + i);
	}
	for(int i = 0; i < M; ++i) {
		scanf("%d", b + i);
		sums[i + 1] = sums[i] + b[i];
	}
	for(int i = 0; i < N; ++i) {
		int high = min(i + 1, M);
		int low = max(0, M - (N - i));
		(a[i] += sums[high] - sums[low]) %= C;
	}
	for(int i = 0; i < N; ++i) {
		if (i > 0) {
			printf(" ");
		}
		printf("%d",a[i]);
	}
	printf("\n");
	return 0;
}