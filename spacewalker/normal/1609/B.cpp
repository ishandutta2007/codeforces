#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 1000010;

char s[NMAX];
int main() {
	int n, q; scanf("%d %d", &n, &q);
	scanf("%s", s);
	if (n < 3) {
		while (q--) printf("0\n");
		return 0;
	}
	vector<int> isABC(n - 2);
	for (int i = 0; i + 2 < n; ++i) {
		if (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') isABC[i] = 1;
	}
	int ans = accumulate(begin(isABC), end(isABC), 0);
	while (q--) {
		int pos; char c; scanf("%d %c", &pos, &c); --pos;
		s[pos] = c;
		for (int j = pos - 2; j <= pos + 2; ++j) {
			if (j < 0 || n <= j + 2) continue;
			int newABC = 0;	
			if (s[j] == 'a' && s[j+1] == 'b' && s[j+2] == 'c') newABC = 1;
			ans += newABC - isABC[j];
			isABC[j] = newABC;
		}
		printf("%d\n", ans);
	}
}