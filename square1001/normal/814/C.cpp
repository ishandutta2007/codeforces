#include <cstdio>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, q, x, d[1509][26]; char s[1509], c[4];
int main() {
	scanf("%d %s %d", &n, s, &q);
	for (int i = 0; i < q; i++) {
		scanf("%d %s", &x, c);
		if (d[x][c[0] - 97]) printf("%d\n", d[x][c[0] - 97]);
		else {
			int ret = 0, l = 0, cnt = 0;
			for (int i = 0; i < n; i++) {
				if (s[i] != c[0]) cnt++;
				while (cnt > x) if (s[l++] != c[0]) cnt--;
				ret = max(ret, i - l + 1);
			}
			printf("%d\n", ret); d[x][c[0] - 97] = ret;
		}
	}
	return 0;
}