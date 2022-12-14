#include <bits/stdc++.h>
using namespace std;
int a[11111], b[11111], cnt, n;
int main() {
//	freopen("A.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		b[cnt++] = 1;
		while (cnt > 1) {
			if (b[cnt-1] == b[cnt-2]) b[cnt-2]++, cnt--;
			else break;
		}
	}
	for (int i = 0; i < cnt; i++) printf("%d ", b[i]);
}