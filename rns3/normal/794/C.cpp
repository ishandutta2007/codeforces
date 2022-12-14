#include <bits/stdc++.h>
using namespace std;

#define N 300020

int n;
char s[N], t[N], ans[N];

int main() {
	gets(s + 1);
	gets(t + 1);
	n = strlen(s + 1);
	sort(s + 1, s + n + 1);
	sort(t + 1, t + n + 1, greater<char>());
	int u = 1, v = 1, uu = (n + 1) / 2, vv = n / 2, i;
    for (i = 1; i <= n; i ++) {
		if (i % 2) {
			if (s[u] < t[v]) ans[i] = s[u++];
			else {
				for (int j = n; j >= i; j --) {
					if((n - j) % 2 == 0) ans[j] = s[uu--];
					else ans[j] = t[vv--];
				}
				break;
			}
		}
		else {
			if (t[v] > s[u]) ans[i] = t[v++];
			else {
				for (int j = n; j >= i; j --) {
					if ((n - j) % 2 == 0) ans[j] = t[vv--];
					else ans[j] = s[uu--];
				}
				break;
			}
		}
    }
	puts(ans + 1);
	return 0;
}