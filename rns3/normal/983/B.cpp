#include <bits/stdc++.h>

using namespace std;



#define N 5050



int a[N];

int b[N][N];

int n;



void build() {

	for (int i = 1; i <= n; i ++) b[1][i] = a[i];

	for (int k = 2; k <= n; k ++) {

		for (int i = 1; i <= n - k + 1; i ++) b[k][i] = b[k-1][i] ^ b[k-1][i+1];

	}

	for (int i = 1; i <= n; i ++) for (int k = 2; k <= n + 1 - i; k ++) b[k][i] = max(b[k-1][i], b[k][i]);

}



#define M 101010



int le[M], ri[M], ans[M];



vector <int> v[N];



bool cmp(int i, int j) {

	return le[i] > le[j];

}



void solve() {

	for (int R = 1; R <= n; R ++) {

		sort(v[R].begin(), v[R].end(), cmp);

		int L = R;

		int now = 0;

		for (int i = 0; i < v[R].size(); i ++) {

			int to = le[v[R][i]];

			while (L >= to) now = max(now, b[R-L+1][L]), L --;

			ans[v[R][i]] = now;

		}

	}

}



int main() {

	//freopen("r.in", "r", stdin);

	int q;

	scanf("%d", &n);

	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);

	build();

	scanf("%d", &q);

	for (int i = 1; i <= q; i ++) {

		scanf("%d %d", &le[i], &ri[i]);

		v[ri[i]].push_back(i);

	}

	solve();

	for (int i = 1; i <= q; i ++) printf("%d\n", ans[i]);



	return 0;

}