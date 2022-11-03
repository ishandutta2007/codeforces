#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N, M;

void solve() {
	scanf("%d%d", &N, &M);
	set<int> bs;
	for (int i = 1; i <= M; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		bs.insert(b);
	}
	for (int i = 1; i <= N; ++i) if (!bs.count(i)) {
		for (int j = 1; j <= N; ++j) if (j != i) printf("%d %d\n", i, j);
		return;
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}