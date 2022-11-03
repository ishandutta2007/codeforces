#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

char s[100005];

void solve() {
	scanf("%s", s + 1);
	int N = strlen(s + 1);
	int is = 0, es = 0;
	bool sh = 1;
	repi(i, N) {
		if (es && s[i] == '0' && s[i - 1] == '1') sh = 0;
		if (s[i] == '1') ++is;
		else ++es;
	}
	if (!es) puts("0");
	else if (sh) puts("1");
	else puts("2");
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}