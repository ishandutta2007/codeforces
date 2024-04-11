#include <bits/stdc++.h>

using namespace std;

void solve() {
	char s[50];
	scanf("%s", s);
	int n = (int) strlen(s);
	int l = 0, r = n - 1;
	while (n--) {
		if (s[l] == 'a' + n)++l;
		else if (s[r] == 'a' + n)--r;
		else {
			printf("NO\n");
			return;
		}
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