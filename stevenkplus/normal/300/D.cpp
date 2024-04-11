#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXK = 1010;
const int MAXSTEP = 30;
const int MOD = 7340033;

int ar[MAXSTEP][MAXK];

void mult(int *a, int *b) {
	for(int i = MAXK - 1; i >= 0; --i) {
		int fin = 0;
		for(int j = 0; j <= i; ++j) {
			ll x = a[j];
			ll y = b[i - j];
			ll add = x * y;
			add %= MOD;
			fin += add;
			fin %= MOD;
		}
		b[i] = fin;
	}
}

int Q;
int N, K;

int main() {
	ar[0][0] = 1;
	for(int i = 0; i + 1 < MAXSTEP; ++i) {
		for(int j = 0; j < MAXK; ++j) {
			ar[i + 1][j] = ar[i][j];
		}
		mult(ar[i + 1], ar[i + 1]);
		mult(ar[i + 1], ar[i + 1]);
		for(int j = MAXK - 1; j > 0; --j) {
			ar[i + 1][j] = ar[i + 1][j - 1];
		}
		ar[i + 1][0] = 1;
	}

	scanf("%d", &Q);
	for(int q = 0; q < Q; ++q) {
		scanf("%d %d", &N, &K);
		int cnt = 0;
		while (N > 1 && N % 2 == 1) {
			N = (N - 1) / 2;
			++cnt;
		}
		int ans = ar[cnt][K];
		printf("%d\n", ans);
	}

	return 0;
}