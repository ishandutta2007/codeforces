#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 350;
const int MAXK = 100100;

int ans1[MAXK], ans2[MAXK];

int targ[MAXN];
int ar[MAXN];

int N;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i) {
		scanf("%d", targ + i);
	}

	int K = 0;
	for(int i = 1; i <= N; ++i) {
		scanf("%d", ar + i);
	}
	for(int i = 1; i <= N; ++i) {
		int j = i;
		while (ar[j] != targ[i]) ++j;
		while (j != i) {
			swap(ar[j], ar[j - 1]);
			ans1[K] = j - 1;
			ans2[K] = j;
			++K;
			--j;
		}
	}

	printf("%d\n", K);
	for(int i = 0; i < K; ++i) {
		printf("%d %d\n", ans1[i], ans2[i]);
	}
	return 0;
}