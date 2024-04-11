#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
#define fi first
#define se second

const int MAXN = 100100;

pii ar[MAXN];
int assign[MAXN];
int diff(int a, int b) {
	return abs (a - b);
}
int N,H;
int main() {
	scanf("%d %d", &N, &H);
	for(int i = 0; i < N; ++i) {
		int tmp;
		scanf("%d", &tmp);
		ar[i] = pii(tmp, i);
	}
	for(int i = 0; i < N; ++i) {
		assign[i] = 2;
	}
	sort(ar, ar + N);
	int m1 = ar[N - 1].fi + ar[N - 2].fi;
	int m2 = ar[N - 1].fi + ar[0].fi + H;
	int a = ar[0].fi + ar[1].fi + H;
	int b = (N > 2 ? ar[1].fi + ar[2].fi : a);
	int c = ar[0].fi + ar[1].fi;
	int d1 = diff(max(m1, m2), min(a, b));
	int d2 = diff(m1, c);
	if (d1 < d2) {
		printf("%d\n", d1);
		assign[ar[0].se] = 1;
	} else {
		printf("%d\n", d2);
		assign[ar[0].se] = 2;
	}
	for(int i = 0; i < N; ++i) {
		if (i > 0) printf(" ");
		printf("%d", assign[i]);
	}
	printf("\n");
	return 0;
}