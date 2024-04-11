#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

char s[15];

void solve() {
	int N;
	scanf("%d", &N);
	scanf("%s", s);
	if (N == 5) {
		sort(s, s + N);
		if (!strcmp(s, "Timru")) {
			puts("YES");
			return;
		}
	}
	puts("NO");
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}