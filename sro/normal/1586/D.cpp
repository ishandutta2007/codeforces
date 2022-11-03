#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N;
int l[105], r[105];
int ans[105];

int inline queryL(int pos) {
	printf("?");
	for (int i = 1; i <= N; ++i) printf(" %d", i == pos ? 1 : 2);
	puts(""); fflush(stdout);
	int res; scanf("%d", &res);
	return res;
}

int inline queryR(int pos) {
	printf("?");
	for (int i = 1; i <= N; ++i) printf(" %d", i == pos ? 2 : 1);
	puts(""); fflush(stdout);
	int res; scanf("%d", &res);
	return res;
}

int main() {
	scanf("%d", &N);
	int be = -1;
	for (int i = 1; i <= N; ++i) {
		int lp = queryL(i), rp = queryR(i);
		if (!lp) be = i;
		if (lp && lp != i) l[i] = lp, r[lp] = i;
		if (rp && rp != i) r[i] = rp, l[rp] = i;
	}
	for (int i = 1; i <= N; ++i) {
		ans[be] = i;
		be = r[be];
	}
	printf("!");
	for (int i = 1; i <= N; ++i) printf(" %d", ans[i]);
	puts(""); fflush(stdout);
	return 0;
}