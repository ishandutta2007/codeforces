#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	char seq[n];
	int bpfx[n + 1], ans = 0;
	bpfx[0] = 0;
	for (int i = 0; i < n; ++i) scanf(" %c", &seq[i]);
	for (int i = 0; i < n; ++i) {
		if (seq[i] == '(') bpfx[i + 1] = bpfx[i] + 1;
		else bpfx[i + 1] = bpfx[i] - 1;
	}
	if (bpfx[n] != 0) {
		printf("-1");
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		if (bpfx[i - 1] < 0 || bpfx[i] < 0) ++ans;
	}
	printf("%d", ans);
	return 0;
}