#include <bits/stdc++.h>

using namespace std;

char s[500005];
char ss[500005];
char k[100];
int num[100], vis[100];

void solve() {
	scanf("%s", s);
	int n = strlen(s);
	int tot = 0, cnt = 0;
	memset(num, 0, sizeof num);
	for (int i = 0; i < n; ++i) {
		if (!num[s[i] - 'a']) ++tot;
		++num[s[i] - 'a'];
	}
	memset(vis, 0, sizeof vis);
	for (int i = n - 1; i >= 0; --i) {
		if (!vis[s[i] - 'a']) {
			if (num[s[i] - 'a'] % tot) {
				printf("-1\n");
				return;
			}
			k[cnt++] = s[i];
			num[s[i] - 'a'] /= tot--;
			vis[s[i] - 'a'] = 1;
		}
	}
	int pos = 0, sum = 0;
	for (int i = 0; i < 26; ++i) sum += num[i];
	while (sum) {
		if (!num[s[pos] - 'a']) {
			printf("-1\n");
			return;
		}
		--num[s[pos++] - 'a'];
		--sum;
	}
	int p = 0;
	memset(vis, 0, sizeof vis);
	for (int i = cnt; i >= 0; --i) {
		if (i < cnt) vis[k[i] - 'a'] = 1;
		for (int j = 0; j < pos; ++j) {
			if (!vis[s[j] - 'a']) ss[p++] = s[j];
			if (p > n) {
				printf("-1\n");
				return;
			}
		}
	}
	ss[p] = '\0';
	if (strcmp(s, ss) != 0) {
		printf("-1\n");
		return;
	}
	s[pos] = '\0';
	printf("%s ", s);
	for (int i = cnt - 1; i >= 0; --i) {
		putchar(k[i]);
	}
	putchar('\n');
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}