#include <cstdio>
#include <algorithm>
using namespace std;


const int MAXN = 100100;

int mins(int h, int m) {
	return 60 * h + m;
}
int cnts[MAXN];

int main() {
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		cnts[mins(a,b)]++;
	}
	int m = 0;
	for(int i = 0; i < MAXN; ++i) {
		m = max(m,cnts[i]);
	}
	printf("%d\n", m);
}