#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int n, a[100010], mx[10010], total[10010], ans, N;

void go(int i, int placed) {
	if (i * 2 >= N) return;

	int r = mx[1] - mx[i * 2] - placed;
	ans += r;
	go(i * 2, placed + r);

	r = mx[1] - mx[i * 2 + 1] - placed;
	ans += r;
	go(i * 2 + 1, placed + r);
}

int main() {
	scanf("%d", &n);
	N = (1 << (n + 1));
	for (int i = 2; i <= N - 1; i++) {
		scanf("%d", &a[i]);
		total[i] = total[i / 2] + a[i];
	}
	for (int i = N - 1; i >= 1; i--) {
		mx[i] = total[i];
		if (i * 2 < N) mx[i] = max(mx[i], mx[i * 2]);
		if (i * 2 + 1 < N) mx[i] = max(mx[i], mx[i * 2 + 1]);
	}
	ans = 0;
	go(1, 0);
	printf("%d\n", ans);
	return 0;
}