#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N;
int s[200005], f[200005];

void solve() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", s + i);
	for (int i = 1; i <= N; ++i) scanf("%d", f + i);
	for (int i = 1; i <= N; ++i) printf("%d%c", f[i] - max(s[i], f[i - 1]), " \n"[i == N]);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}