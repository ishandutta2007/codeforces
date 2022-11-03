#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

void solve() {
	int n;
	scanf("%d", &n);
	if (n % 3 == 0) printf("%d %d %d\n", n / 3, n / 3 + 1, n / 3 - 1);
	else if (n % 3 == 1) printf("%d %d %d\n", n / 3, n / 3 + 2, n / 3 - 1);
	else printf("%d %d %d\n", n / 3 + 1, n / 3 + 2, n / 3 - 1);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}