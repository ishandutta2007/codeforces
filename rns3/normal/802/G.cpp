#include <bits/stdc++.h>
using namespace std;

char s[1010], t[9] = "heidi";
int n;

int main() {
	gets(s);
	int n = strlen(s);
	int now = 0;
	for (int i = 0; i < n; i ++) {
		if (t[now] == s[i]) {
			now ++;
			if (now == 5) break;
		}
	}
	if (now == 5) puts("YES");
	else puts("NO");
	return 0;
}