#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N;
int a[105];

bool inline isushu(int x) {
	for (int i = 2; i * i <= x; ++i) if (x % i == 0) return 0;
	return 1;
}

void solve() {
	scanf("%d", &N);
	int sm = 0;
	for (int i = 1; i <= N; ++i) scanf("%d", a + i), sm += a[i];
	if (!isushu(sm)) {
		printf("%d\n", N);
		for (int i = 1; i <= N; ++i) printf("%d ", i);
		puts("");
		return;
	}
	printf("%d\n", N - 1);
	bool hs = 0;
	for (int i = 1; i <= N; ++i) {
		if (!hs && a[i] % 2) {
			hs = 1;
			continue;
		}
		printf("%d ", i);
	}
	puts("");
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}