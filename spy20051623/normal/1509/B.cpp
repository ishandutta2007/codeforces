#include <bits/stdc++.h>

using namespace std;
char s[100005];

void solve() {
	int n;
	scanf("%d", &n);
	getchar();
	gets(s);
	int pre = 0;
	int nee = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'T') {
			++pre;
		} else {
			if (!pre) {
				printf("NO\n");
				return;
			} else {
				--pre;
				++nee;
			}
		}
	}
	if (nee != pre) {
		printf("NO\n");
		return;
	}
	pre = nee = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] == 'T') {
			++pre;
		} else {
			if (!pre) {
				printf("NO\n");
				return;
			} else {
				--pre;
				++nee;
			}
		}
	}
	if (nee != pre) {
		printf("NO\n");
		return;
	}
	printf("YES\n");
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