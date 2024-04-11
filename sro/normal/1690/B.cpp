#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N;
int a[50005], b[50005];

void solve() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", a + i);
	for (int i = 1; i <= N; ++i) scanf("%d", b + i);
	int mxc = 0;
	for (int i = 1; i <= N; ++i) mxc = max(mxc, a[i] - b[i]);
	for (int i = 1; i <= N; ++i) if ((b[i] && a[i] - b[i] != mxc) || a[i] - b[i] > mxc) return void(puts("NO"));
	puts("YES");
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}