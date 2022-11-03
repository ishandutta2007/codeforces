#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N;
char s[200005];

void solve() {
	scanf("%d", &N);
	scanf("%s", s);
	int pt = 0;
	vector<ll> ac;
	ll cp = 0;
	for (int i = 0; i < N; ++i) {
		if (s[i] == 'L') cp += i;
		else cp += N - i - 1;
	}
	for (int i = 0, j = N - 1; i < j; ++i, --j) {
		if (s[i] == 'L') cp += N - i - 1 - i, ac.push_back(cp);
		if (s[j] == 'R') cp += j - (N - j - 1), ac.push_back(cp);
	}
	if (!SZ(ac)) ac.push_back(cp);
	while (SZ(ac) < N) ac.push_back(ac.back());
	for (int i = 0; i < SZ(ac); ++i) printf("%lld%c", ac[i], " \n"[i == SZ(ac) - 1]);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}