#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
int t, n, a[N];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i ++) if (a[i] == i) cnt ++;
		if (cnt == n) {
			printf("0\n"); continue;
		}
		if (cnt == 0) {
			printf("1\n"); continue;
		} 

		int ps = 0;
		for (int i = 1; i <= n; i ++) {
			if (a[i] == i) ps ++;
			else break;
		}
		for (int i = n; i >= 1; i --) {
			if (a[i] == i) ps ++;
			else break;
		}
		if (ps == cnt) printf("1\n");
		else printf("2\n");
	}
}