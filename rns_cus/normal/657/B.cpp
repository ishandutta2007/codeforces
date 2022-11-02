#include <bits/stdc++.h>
using namespace std;
#define M 1000010
typedef long long LL;

LL a[M], U[M], D[M], b[M];
int n, L, sign, m, pos[M], flag[M];

int main() {
	scanf("%d %d", &n, &L);
	for (int i = 0; i <= n; i++) {
		scanf("%I64d", &a[i]); b[i] = a[i];
		U[i] = L - a[i]; D[i] = a[i] + L;
	}
	for (int i = 0; i <= n + 60; i++) {
		LL d = a[i];
		sign = (a[i] >= 0 ? 1 : -1);
		a[i] = a[i] % 2;
		if (a[i] < 0) a[i] = -a[i];
		d -= a[i]; a[i+1] += d / 2;
	}
	if (sign < 0) {
		memset(a, 0, sizeof(a));
		for (int i = 0; i <= n; i++) a[i] = -b[i], b[i] = a[i], U[i] = L - a[i], D[i] = a[i] + L;
	}
	for (int i = 0; i <= n + 60; i++) {
		LL d = a[i];
		sign = (a[i] >= 0 ? 1 : -1);
		a[i] = a[i] % 2;
		if (a[i] < 0) a[i] = -a[i];
		d -= a[i]; a[i+1] += d / 2;
		if (a[i] & 1) pos[m++] = i, flag[i] = 1;
	}

	if (m > 1 && pos[m-1] - pos[0] > 31) return puts("0"), 0;
  int ans = 0;
  for (int i = min(pos[0], n); i >= max(0, pos[0] - 32); i--) {
  	LL tp = 0;
  	if (pos[m-1] - i > 63) break;
  	for (int j = i; j <= pos[m-1]; j++) {
  		tp = tp + (1LL << (j - i)) * flag[j];
  	}
  	//printf("%d %I64d %I64d\n", i, tp, D[i]);
  	if (i == n && !(b[n] - sign * tp)) continue;
  	if (sign > 0 && tp <= D[i]) ans++;
  	else if (sign < 0 && tp <= U[i]) ans++;
  }
  printf("%d\n", ans);
}