#include <bits/stdc++.h>
using namespace std;
#define N 1001001

int n, k, a[N];
int gas[N], cnt, L, R;

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	int i = 1, j = 1;
	while (i <= n) {
		if (gas[a[j]]) {
            if (R - L <= j - i) L = i, R = j;
			gas[a[j]] ++, j ++;
		}
		else {
			if (cnt < k) {
                gas[a[j]] = 1;
                if (R - L <= j - i) L = i, R = j;
                cnt ++, j ++;
			}
			else {
				if (gas[a[i]] > 1) gas[a[i]] --, i ++;
				else gas[a[i]] = 0, cnt --, i ++;
			}
		}
		if (j > n) break;
	}
	printf("%d %d\n", L, R);
	return 0;
}