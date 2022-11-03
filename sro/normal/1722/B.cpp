#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

char s[105], t[105];
int N;

void solve() {
	scanf("%d", &N);
	scanf("%s", s);
	scanf("%s", t);
	for (int i = 0; i < N; ++i) {
		if (s[i] == 'B') s[i] = 'G';
		if (t[i] == 'B') t[i] = 'G';
	}
	if (!strcmp(s, t)) puts("yes");
	else puts("no");
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}