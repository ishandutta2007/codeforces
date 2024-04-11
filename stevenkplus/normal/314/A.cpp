#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;
const int MAXN = 200100;

int ar[MAXN];
int N, K;

int main() {
	scanf("%d %d", &N, &K);

	for(int i = 1; i <= N; ++i) {
		scanf("%d", ar + i);
	}

	ld sum = 0;
	int I = 1;
	ld NN = N;
	for(int i = 1; i <= N; ++i) {
		ld d = sum - (NN - I) * (I - 1) * ar[i];
		if (d < K) {
			printf("%d\n", i);
			--NN;
		} else {
			sum += (I - 1) * ar[i];
			++I;
		}
	}

	return 0;
}