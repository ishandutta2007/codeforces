#include <bits/stdc++.h>
using namespace std;
#define N 500500

int n, a[N], b[N], x[N];
set <int> s[N];
set <int> :: iterator it;
map <int, int> mp;
int f[N];

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d %d", &a[i], &b[i]);
	for (int i = 0; i < n; i ++) x[i] = a[i+1];
	sort(x, x + n);
	int m = unique(x, x + n) - x;
	for (int i = 0; i < m; i ++) mp[x[i]] = i;
	for (int i = 1; i <= n; i ++) s[mp[a[i]]].insert(b[i]);
	f[m] = 0;
	for (int i = m - 1; i >= 0; i --) {
		f[i] = f[i+1];
		it = s[i].begin();
		int y = *it;
		int k = lower_bound(x, x + m, y + 1) - x;
		f[i] = max(f[i], f[k] + 1);
	}
	printf("%d\n", f[0]);
}