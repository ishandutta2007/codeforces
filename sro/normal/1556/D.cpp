#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int inline getsum(int i, int j) {
	printf("or %d %d\n", i, j); fflush(stdout);
	int sm; scanf("%d", &sm);
	printf("and %d %d\n", i, j); fflush(stdout);
	int nsm; scanf("%d", &nsm);
	return sm + nsm;
}

int N, K;
int a[10005];

int main() {
	scanf("%d%d", &N, &K);
	int s12 = getsum(1, 2), s23 = getsum(2, 3), s13 = getsum(1, 3);
	a[1] = (s12 + s13 - s23) / 2;
	a[2] = s12 - a[1]; a[3] = s23 - a[2];
	for (int i = 4; i <= N; ++i) {
		int s = getsum(1, i);
		a[i] = s - a[1];
	} 
	sort(a + 1, a + N + 1);
	printf("finish %d\n", a[K]);
	fflush(stdout);
	return 0;
}