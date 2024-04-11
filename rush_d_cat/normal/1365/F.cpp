#include <bits/stdc++.h>
using namespace std;
/*
map< vector<int>, int > mp;
void dfs(vector<int> vec) {
	if (mp[vec]) return;
	mp[vec] = 1;
	int sz = vec.size();
	// for (auto x: vec) printf("%d ", x); printf("\n");
	for (int i = 1; i <= sz / 2; i ++) {
		vector<int> tmp;
		int len = i;
		int sz = vec.size();
		tmp.clear();
		// [1, len]   [sz - len + 1, sz]
		for (int j = sz - len; j < sz; j ++) tmp.push_back(vec[j]);
		for (int j = len; j < sz - len; j ++) tmp.push_back(vec[j]);
		for (int j = 0; j < len; j ++) tmp.push_back(vec[j]);
		dfs(tmp);
	}
}	
int main() {
	vector<int> vec;
	int T = 7;
	for (int i = 1; i <= T; i ++) vec.push_back(i);
	dfs(vec);
	printf("# %d\n", mp.size());
	for (auto p: mp) {
		for (auto pp: p.first) {
			printf("%d ", min(pp, T+1-pp)); 
		}
		printf("\n");
	}
}
*/

const int N = 502;
int t;
int val[N];

int solve(int n, pair<int, int> a[]) {
	for (int i = 1; i <= n / 2; i ++) {
		int x = i, y = n + 1 - i;
		// printf("%d(%d) %d(%d)\n", x, a[x], y, a[y]);
		if (a[x] > a[y]) {
			swap(a[x], a[y]); 
		}
	}
	for (int i = 1; i <= n / 2; i ++) {
		a[i] = make_pair(a[i].first, - a[n + 1 - i].first);
	}
	sort(a + 1, a + 1 + n/2);
	int pos = (n+1)/2 + 1;
	for (int i = pos, j = n/2; i <= n; i ++, j --) {
		a[i].first = a[j].second;
	}
	//for (int i = 1; i <= n; i ++) printf("%d ", a[i]); printf("\n");
}
int n;pair<int, int> a[N], b[N];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i].first);
		for (int i = 1; i <= n; i ++) scanf("%d", &b[i].first);
		solve(n, a); solve(n, b);
		bool ok = 1;
		for (int i = 1; i <= n; i ++) if (a[i].first != b[i].first) ok = 0;
		printf("%s\n", ok ? "Yes" : "No");
	}
}