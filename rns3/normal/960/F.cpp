#include <bits/stdc++.h>

using namespace std;



#define N 101010



int a[N], b[N], c[N];



int n, m;



vector <int> v[N];

vector <int> u;

vector <int> fnk[N];

int sz[N];



int myfind(int i, int val) {

	int j = lower_bound(v[i].begin(), v[i].end(), val) - v[i].begin();

	return j;

}



int query(int i, int j) {

	int rlt = 0;

	for (int k = j + 1; k; k -= k & -k) rlt = max(rlt, fnk[i][k-1]);

	return rlt;

}



void update(int i, int j, int val) {

	for (int k = j + 1; k <= sz[i]; k += k & -k) fnk[i][k-1] = max(fnk[i][k-1], val);

}



int main() {

	//freopen("r.in", "r", stdin);

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= m; i ++) scanf("%d %d %d", &a[i], &b[i], &c[i]), c[i] ++;

	for (int i = 1; i <= m; i ++) v[a[i]].push_back(c[i] - 1), v[b[i]].push_back(c[i]);

	for (int i = 1; i <= n; i ++) {

		u.clear();

		v[i].push_back(0);

		sort(v[i].begin(), v[i].end());

		for (int j = 0; j < v[i].size(); j ++) if (!j || v[i][j] != v[i][j-1]) u.push_back(v[i][j]);

		v[i] = u;

		sz[i] = v[i].size();

		fnk[i].resize(sz[i], 0);

	}

	int ans = 0;

	for (int i = 1; i <= m; i ++) {

		int k = myfind(a[i], c[i] - 1);

		int val = query(a[i], k);

		k = myfind(b[i], c[i]);

		update(b[i], k, val + 1);

		ans = max(ans, val + 1);

	}

	printf("%d\n", ans);







	return 0;

}