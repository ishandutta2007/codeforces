#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

int A[MAXN];
int B[MAXN];
int prefs[MAXN];

int N, M, C;

int main() {
	scanf("%d %d %d", &N, &M, &C);
	for(int i = 0; i < N; ++i) {
		scanf("%d", A + i);
	}

	for(int i = 0; i < M; ++i) {
		scanf("%d", B + i);
	}


	for(int i = 0; i < M; ++i) {
		prefs[i + 1] = (prefs[i] + B[i]) % C;
	}

	for(int i = 0; i < N; ++i) {
		int high = min(M, i + 1);
		int low = max(0, i + M - N);
		int ans = (A[i] + prefs[high] - prefs[low]) % C;
		if (ans < 0) ans += C;

		if (i) printf(" ");
		printf("%d", ans);
	}

	printf("\n");
	return 0;
}