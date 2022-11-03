#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N;
int a[2114];

void solve() {
	scanf("%d", &N);
	bool can = 1;
	repi(i, N) {
		scanf("%d", a + i);
		if ((a[i] & 1) != (i & 1)) can = 0;
	}
	if (!can) return puts("-1"), void();
	vector<int> opers;
	for (int i = N; i > 1; i -= 2) {
		int ip, jp;
		repi(j, N) if (a[j] == i) ip = j;
		opers.push_back(ip);
		reverse(a + 1, a + ip + 1);
		repi(j, N) if (a[j] == i - 1) jp = j;
		opers.push_back(jp - 1);
		reverse(a + 1, a + jp);
		opers.push_back(i);
		reverse(a + 1, a + i + 1);
		repi(j, N) if (a[j] == i) ip = j;
		opers.push_back(ip);
		reverse(a + 1, a + ip + 1);
		opers.push_back(i);
		reverse(a + 1, a + i + 1);
	}
	printf("%d\n", SZ(opers));
	rep(i, SZ(opers)) printf("%d ", opers[i]);
	puts("");
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}