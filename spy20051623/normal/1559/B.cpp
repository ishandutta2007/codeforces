#include <bits/stdc++.h>

using namespace std;

char s[1000];

void solve() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	int pos = -1;
	for (int i = 0; i < n; ++i) {
		if (s[i] != '?') {
			pos = i;
			break;
		}
	}
	if (pos == -1) {
		for (int i = 0; i < n; ++i) {
			s[i] = i & 1 ? 'R' : 'B';
		}
		printf("%s\n", s);
		return;
	}
	for (int i = pos - 1; i >= 0; --i) {
		s[i] = s[i + 1] == 'R' ? 'B' : 'R';
	}
	while (pos < n) {
		if (s[pos] != '?') {
			++pos;
			continue;
		}
		s[pos] = s[pos - 1] == 'R' ? 'B' : 'R';
		++pos;
	}
	printf("%s\n", s);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}