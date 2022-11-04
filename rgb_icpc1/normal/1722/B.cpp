#include <bits/stdc++.h>
using namespace std;
char a[105], b[105];
int main() {
	int tc, n;
	cin >> tc;
	while (tc --) {
		cin >> n;
		cin >> a >> b;
		bool ok = true;
		for (int i = 0; i < n; i ++) {
			if (a[i] == 'G') a[i] = 'B';
			if (b[i] == 'G') b[i] = 'B';
		}
		if (strncmp(a, b, n) == 0) puts("YES");
		else puts("NO");
	}
	return 0;
}