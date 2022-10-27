#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const int inf = 1e9;
int a[N];
int ask(int x) {
	if (a[x]) return a[x];
	printf("? %d\n", x);
	fflush(stdout);
	int y; scanf("%d", &y);
	return a[x] = y;
}

void solve(int l, int r) {
	if (l + 2 == r) {
		printf("! %d\n", l + 1); fflush(stdout); exit(0);
	}
	int mid = (l + r) >> 1;
	ask(mid-1); ask(mid); ask(mid+1);
	if (a[mid] < a[mid-1] && a[mid] < a[mid+1]) {
		printf("! %d\n", mid); fflush(stdout); exit(0);
	}
	if (a[mid-1] < a[mid] && a[mid] < a[mid+1])
		solve(l, mid);
	else
		solve(mid, r);
}
int main() {
	int n;
	scanf("%d", &n);
	a[0] = a[n+1] = inf;
	solve(0, n+1);
}