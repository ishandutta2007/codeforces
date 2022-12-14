#include <bits/stdc++.h>
using namespace std;
#define M 200010
int pos[M], n, x;
int main() {
//	freopen("B.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &x), pos[x] = i;
	__int64 ans = 0;
	for (int i = 2; i <= n; i++) ans += abs(pos[i] - pos[i-1]);
	printf("%I64d\n", ans);
}