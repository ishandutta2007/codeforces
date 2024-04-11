#include <bits/stdc++.h>
using namespace std;

char s[11];

int main() {
//	freopen("a.in", "r", stdin);
	for (int i = 0; i < 8; i ++) {
		scanf("%s", s);
		for (int j = 1; j < 8; j ++) {
			if (s[j] == s[j-1]) {
				puts("NO"); return 0;
			}
		}
	}
	puts("YES");
	return 0;
}