#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t, n;
char s[N];
int main() {
	scanf("%d", &t);

	while (t --) {
		scanf("%d", &n);
		scanf("%s", s + 1);
		
		if (n % 2 == 0) {
			int c[2] = {0};
			for (int i = 1; i <= n; i ++) {
				if (i % 2 == 0) {
					c[(s[i] - '0') % 2] ++;
				}
			}
			if (c[0]) printf("2\n"); else printf("1\n");
		} else {
			int c[2] = {0};
			for (int i = 1; i <= n; i ++) {
				if (i % 2 == 1) {
					c[(s[i] - '0') % 2] ++;
				}
			}
			if (c[1]) printf("1\n"); else printf("2\n");
		}
	}
}