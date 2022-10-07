#include <cstdio>

using namespace std;

const int MAXN = 100100;

int sav[MAXN];

int N, K;
int main() {
	scanf("%d %d", &N, &K);
	int a = -1;
	int b = -1;
	for(int i = 0; i < N; ++i) {
		int c;
		scanf("%d", &c);
		if (b == c) {
			continue;
		}
		if (b != -1) {
			sav[b]++;
			sav[c]++;
		}
		if (a != -1 && a != c) {
			sav[b]--;
		}
		a = b;
		b = c;
	}
	int best = 1;
	for(int i = 1; i <= K; ++i) {
		if (sav[i] > sav[best]) {
			best = i;
		}
	}
	printf("%d\n", best);
	return 0;
}