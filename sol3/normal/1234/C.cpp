#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;

int cur, n;
string s[2];

void Solve() {
	cur = 0;
	for (int i = 0;i < n;i++) {
		if (s[cur][i] == '1' || s[cur][i] == '2') continue;
		if (s[cur ^ 1][i] >= '3' && s[cur ^ 1][i] <= '6') cur ^= 1;
		else {
			puts("NO");
			return;
		}
	}
	if (cur == 1) puts("YES");
	else puts("NO");
}

int main() {
	int q;
	cin >> q;
	while (q--) {
		cin >> n >> s[0] >> s[1];
		Solve();
	}
	return 0;
}