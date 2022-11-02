#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 50;
const int mo = 1e9 + 7;

int n, m;
int f[N], a[10];
vector<int> ans;

int getf(int u) {
	if(u == f[u])return u;
	return f[u] = getf(f[u]);
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
		f[i] = i;
	for(int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		for(int i = 1; i <= k; i++)
			scanf("%d", &a[i]);
		if(k == 1) {
			int u = getf(a[1]);
			if(u) {
				ans.push_back(i);
				f[u] = 0;
			}
		}
		else {
			int u = getf(a[1]);
			int v = getf(a[2]);
			if(u == v)continue;
			ans.push_back(i);
			if(u > v)swap(u, v);
			f[v] = u;
		}
	}
	int ans1 = 1;
	for(int i = 0; i < ans.size(); i++)
		ans1 *= 2, ans1 %= mo;
	printf("%d %d\n", ans1, ans.size());
	for(int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
}