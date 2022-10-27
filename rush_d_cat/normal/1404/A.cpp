#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
int t, n, k;
char s[N];
set<int> st[N];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d", &n, &k);
		scanf("%s", s);
		for (int i = 0; i < n; i ++) {
			st[i].clear();
		}
		for (int i = 0; i < n; i ++) {
			if (s[i] != '?')
				st[i % k].insert(s[i]);
		}
		bool fg = true;
		for (int i = 0; i < k; i ++)
			if (st[i].size() == 2) fg = false;
		
		if (! fg) {
			printf("NO\n"); continue;
		}

		int c[2] = {0};
		for (int i = 0; i < k; i ++) {
			if (st[i].size() == 1) {
				c[(*st[i].begin()) - '0'] ++;
			}
		}
		int mx = max(c[0], c[1]);
		if (mx <= k / 2) printf("YES\n");
		else printf("NO\n");
	}
}