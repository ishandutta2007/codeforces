#include <bits/stdc++.h>
using namespace std;
#define N 1001001

char s[N], t[N];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%s %s", s, t);
	int n = strlen(s), m = strlen(t);
	reverse(s, s + n);
	reverse(t, t + m);
	for (int i = n; i < m; i ++) s[n++] = '0';
	s[n] = 0;
	for (int i = m; i < n; i ++) t[m++] = '0';
	t[m] = 0;
	reverse(s, s + n);
	reverse(t, t + m);
	for (int i = 0; i < n; i ++) {
		if (s[i] > t[i]) {
			puts(">"); return 0;
		}
		else if (s[i] < t[i]) {
			puts("<"); return 0;
		}
	}
	puts("=");
	return 0;
}