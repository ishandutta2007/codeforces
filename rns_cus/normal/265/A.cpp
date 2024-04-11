#include <bits/stdc++.h>
using namespace std;

char s[111], t[111];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%s %s", s + 1, t);
	int n = strlen(s + 1), len = strlen(t);
	int x = 1;
	for (int i = 0; i < len && x <= n; i ++) {
		if (s[x] == t[i]) x ++;
	}
	printf("%d\n", x);
	return 0;
}