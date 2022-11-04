#include <bits/stdc++.h>
using namespace std;
int main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	int tc;
	int n;
	char s[15];
	cin >> tc;
	while (tc --) {
		cin >> n;
		memset(s, 0, sizeof s);
		cin >> s;
		if (n != 5) {
			puts("NO");
			continue;
		}
		bool ok = false;
		sort(s, s + n);
		do {
			if (strcmp(s, "Timur") == 0) {
				ok = true;
				break;
			}
		} while (next_permutation(s, s + n));
		if (ok) puts("YES");
		else puts("NO");
	}
	return 0;
}