#include <bits/stdc++.h>
using namespace std;

int cnt[555];

char s[101010];

int main() {
	//freopen("r.in", "r", stdin);
	int n;
	scanf("%d %s", &n, s);
	for (int i = 0; i < n; i ++) cnt[s[i]] ++;
	bool flag = 0;
	for (char c = 'a'; c <= 'z'; c ++) {
		if (cnt[c] > 1) flag = 1;
	}
	if (flag || n == 1) puts("Yes");
	else puts("No");

	return 0;
}