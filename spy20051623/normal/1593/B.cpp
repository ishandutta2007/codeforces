#include <bits/stdc++.h>

using namespace std;

void solve() {
	char s[22];
	scanf("%s", s);
	int n = strlen(s);
	int a, b, p1, p2;
	p1 = p2 = -1;
	for (int i = n - 1; i >= 0; --i) {
		if (p1 == -1 && s[i] == '5') {
			p1 = i;
			continue;
		}
		if (p1 != -1 && (s[i] == '2' || s[i] == '7')) {
			p2 = i;
			break;
		}
	}
	a = n - 1 - p2 - 1;
	p1 = p2 = -1;
	for (int i = n - 1; i >= 0; --i) {
		if (p1 == -1 && s[i] == '0') {
			p1 = i;
			continue;
		}
		if (p1 != -1 && (s[i] == '0' || s[i] == '5')) {
			p2 = i;
			break;
		}
	}
	b = n - 1 - p2 - 1;
	printf("%d\n", min(a, b));
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