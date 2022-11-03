#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N, S;

void solve() {
	scanf("%d%d", &N, &S);
	int vals = N - (N + 1) / 2 + 1;
	printf("%d\n", S / vals);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}