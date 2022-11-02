#include <bits/stdc++.h>
using namespace std;
#define N 200010

int n, m, k, a[N], b[N];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i ++) scanf("%d", a + i);
	sort(a, a + n);
	k --;
	for (int i = 0; i < k; i ++) b[i] = i;
	int ans;
	if (k == 0) ans = n;
	else {
		ans = n - k;
		while (1) {
			int t = -1;
			for (int i = 0; i < k; i ++) {
				t = b[(i+k-1)%k] + 1;
				while (t < n && a[t] < a[b[i]] + m) t ++;
				if (t == n) break;
				b[i] = t;
				ans --;
			}
			if (t == n) break;
		}
	}
	cout<<ans;
    return 0;
}