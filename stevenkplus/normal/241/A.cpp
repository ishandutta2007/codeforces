#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXM = 1100;
int d[MAXM];
int s[MAXM];

int M,K;
int main() {
	scanf("%d %d", &M, &K);
	for(int i = 0; i < M; ++i) {
		scanf("%d", d + i);
	}
	for(int i = 0; i < M; ++i) {
		scanf("%d", s + i);
	}
	int m = 0;
	int f = 0;
	int t = 0;
	for(int i = 0; i < M; ++i) {
		f += s[i];
		m = max(m, s[i]);
		int extr = 0;
		if (f < d[i]) {
			extr = (d[i] - f + m - 1) / m;
		}
		f += extr * m;
		t += extr * K;
		f -= d[i];
		t += d[i];
	}
	printf("%d\n",t);
	return 0;
}