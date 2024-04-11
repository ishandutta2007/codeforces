#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100 + 10;
int t, n, w[N], c[N];

int main() {
	scanf("%d", &t);
	while (t --) {	
		scanf("%d", &n);
		memset(c, 0, sizeof(c));
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &w[i]); c[w[i]] ++;
		}
		int ans = 0;
		for (int s = 0; s <= 2 * n; s ++) {
			int tmp = 0;
			for (int i = 0; i <= s - i; i ++) 
				if (i != s-i)
					tmp += min(c[i], c[s-i]);
				else
					tmp += c[i] / 2;
			ans = max(ans, tmp);
		}
		printf("%d\n", ans);
	}
}