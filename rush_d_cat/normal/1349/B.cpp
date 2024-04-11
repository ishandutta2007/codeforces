#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
int t;
int n, k;
int a[N], b[N], mx[N];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d", &n, &k);
		bool flag = false;
		for (int i = 1; i <= n; i ++){
			scanf("%d", &a[i]);
			if (a[i] == k) flag = true; 
			if (a[i] >= k) b[i] = 1;
			else b[i] = 0;
		}

		if (flag == false) {
			printf("no\n"); continue;
		}
		if (n == 1) {
			printf("yes\n"); continue;
		}
		bool ok = 0;
		for (int i = 1; i <= n; i ++) {
			if (i + 1 <= n && b[i] == 1 && b[i+1] == 1) ok = 1;
			if (i + 2 <= n && b[i] == 1 && b[i+2] == 1) ok = 1;
		}
		printf("%s\n", ok ? "yes" : "no");
	}
}