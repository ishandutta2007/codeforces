#include <bits/stdc++.h>
using namespace std;

#define N 1001001

char s[N], t[N], p[N];

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%s %s", s, t);
	int n = strlen(s), x = 0;
	for (int i = 0; i < n; i ++) {
		if (s[i] == t[i]) p[i] = s[i];
		else {
			x ++;
			if (x & 1) p[i] = s[i];
			else p[i] = t[i];
		}
	}
	if (x & 1) puts("impossible");
	else puts(p);
	return 0;
}