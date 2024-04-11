#include <bits/stdc++.h>
using namespace std;

char s[3];

int main() {
//	freopen("a.in", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			scanf("%s", s);
			if (s[0] != 'B' && s[0] != 'W' && s[0] != 'G') {
				puts("#Color"); return 0;
			}
		}
	}
	puts("#Black&White");
	return 0;
}