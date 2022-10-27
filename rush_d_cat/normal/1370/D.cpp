#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;

int n, k, a[N], b[N];
bool check1() {
	int len = 0, las = 0;
	for (int i = 1; i <= n; i ++) {
		if (b[i] == 1) {
			len ++; las = i; i ++;
		}
	}
	if (len == 0) return 0;
	// printf("%d %d\n", len, (k+1)/2);
	if (las == n && len == k / 2 && k % 2 == 0) return 0;
	return len >= (k + 1) / 2;
}
bool check2() {
	// printf("!\n");
	int len = 0, las = 0;
	for (int i = 2; i <= n; i ++) {
		if (b[i] == 1) {
			len ++; las = i; i ++;
		}
	}
	if (len == 0) return 0;
	// printf("len = %d, k / 2 = %d\n", len, k / 2);
	if (las == n && len * 2 + 1 == k && k % 2 == 1) return 0;
	return len >= k / 2;
}
bool check(int x) {
	// printf("!\n");
	for (int i = 1; i <= n; i ++) {
		if (a[i] <= x) b[i] = 1; else b[i] = 0;
	}
	return check1() || check2();
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	int lef = 0, rig = 1e9;
	// check(1); return 0;
	while (rig - lef > 1) {
		int mid = (lef + rig) / 2;
		// printf("mid = %d, check = %d\n", mid, check(mid));
		if (check(mid)) rig = mid; else lef = mid;		
	}
	printf("%d\n", rig);
}