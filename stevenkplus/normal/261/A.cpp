#include <cstdio>
#include <algorithm>


using namespace std;

const int MAXN = 100100;

int ar[MAXN];

int N, M;

int main() {
	scanf("%d", &M);
	int best = 100100;
	for(int i = 0; i < M; ++i) {
		int q;
		scanf("%d", &q);
		if (q < best) {
			best = q;
		}
	}

	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar + i);
	}

	sort(ar, ar + N);

	int sum =  0;
	int cnt = 0;
	for(int i = N - 1; i >= 0; --i) {
		if (cnt % (best + 2) < best) {
			sum += ar[i];
		}
		++cnt;
	}

	printf("%d\n", sum);
	return 0;
}