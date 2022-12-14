#include <bits/stdc++.h>
using namespace std;

int n, m, i, j;
char s[110], t[] = "CODEFORCES";

int main() {
	gets(s);
	n = strlen(s);
	m = strlen(t);
	for (i = 0; i < min(n, m); i ++) if (s[i] != t[i]) break;
	for (j = 0; j < min(n, m); j ++) if (t[m-j-1] != s[n-j-1]) break;
	if (i + j >= m) puts("YES");
	else puts("NO");
	return 0;
}