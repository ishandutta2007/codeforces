#include <bits/stdc++.h>
using namespace std;

char s[1000010], t[1000010];
int cnt[300][300];

int main () {
	scanf("%s%s", s, t);
	int n = strlen(s), m = strlen(t);
	int l = 0, r = 0;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		while (r < m && s[i] != t[r]) r++, cnt[t[r]][t[r - 1]]++;
		r = min(r, m - 1);
		ans += r - l + 1;
		if (l < m && s[i] == t[l]) l++, cnt[t[l]][t[l - 1]]--;
		if (i + 1 < n && s[i] != s[i + 1]) ans -= max(0, cnt[s[i]][s[i + 1]]);
		if (s[i] == t[r]) r++, cnt[t[r]][t[r - 1]]++;
		r = min(r, m - 1);
	}
	printf("%I64d\n", ans);
	return 0;
}