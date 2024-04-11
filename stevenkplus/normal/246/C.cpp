#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 51;
int ar[MAXN];

int N, K;
int main() {
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar + i);
	}
	sort(ar, ar + N);
	int cur = 0;
	int guys = 0;
	for(int i = 0; i < K; ++i) {
		printf("%d ", 1 + guys);
		printf("%d", ar[cur]);
		for(int j = 0; j < guys; ++j) {
			printf(" %d", ar[N - 1 - j]);
		}
		printf("\n");
	
		cur++;
		if (cur + guys == N) {
			guys++;
			cur = 0;
		}
	}
	return 0;
}