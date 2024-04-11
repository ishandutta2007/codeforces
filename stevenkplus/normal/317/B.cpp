#include <cstdio>
#include <algorithm>

using namespace std;

const int A = 500;
const int MAXN = 1000;
int ar[MAXN][MAXN];

int N, T;

int main() {
	scanf("%d", &N);
	ar[A][A] = N;
	int z = 0;
	while (true) {
		bool done = true;

		for(int i = A - z; i <= A + z; ++i) {
			for(int j = A - z; j <= A + z; ++j) {
				if (ar[i][j] >= 4) {
					if (max(abs(A - i), abs(A - j)) == z) {
						++z;
					}
					done = false;
					int add = ar[i][j] / 4;
					ar[i + 1][j] += add;
					ar[i - 1][j] += add;
					ar[i][j + 1] += add;
					ar[i][j - 1] += add;
					ar[i][j] %= 4;
				}
			}
		}

		if (done) break;
	}

	scanf("%d", &T);
	for(int i = 0; i < T; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		a += A;
		b += A;
		if (a < 0 || b < 0 || a >= MAXN || b >= MAXN) printf("0\n");
		else printf("%d\n", ar[a][b]);
	}
	return 0;
}