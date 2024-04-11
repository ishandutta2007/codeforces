#include <bits/stdc++.h>
using namespace std;

char t[11] = "heidi";
char s[1010];

int main() {
	gets(s);
	int n = strlen(s);
	int cur = 0;
	for (int i = 0; i < n; i ++) if (cur < 5 && t[cur] == s[i]) cur ++;
	puts(cur == 5 ? "YES" : "NO");

	return 0;
}