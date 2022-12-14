#include <bits/stdc++.h>
using namespace std;

#define N 202020

int a[N], b[N], id[N], c[N];

bool cmp(int i, int j) {
	return b[i] > b[j];
}

int  n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++) scanf("%d", &b[i]), id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) c[id[i]] = a[i];
	for (int i = 1; i <= n; i ++) printf("%d%c", c[i], i == n ? '\n' : ' ');

	return 0;
}