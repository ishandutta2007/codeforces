#include <bits/stdc++.h>

using namespace std;



const int mod = 1e9 + 7;



#define N 202020



int n;



vector <int> v[N];



bool flag[N];



int a[N], b[N], val[N];



void dfs(int x, int y) {

	flag[x] = !flag[y];

	if (flag[x]) a[x] = 1, b[x] = 0;

	else a[x] = 0, b[x] = 1;

	for (int i = 0; i < v[x].size(); i ++) {

		int z = v[x][i];

		if (z == y) continue;

		dfs(z, x);

		a[x] += a[z];

		b[x] += b[z];

	}

}



int ans;



vector <int> X[N], Y[N];



void DFS(int x, int y) {

	int A = a[1], B = b[1];

	for (int i = 0; i < v[x].size(); i ++) {

		int z = v[x][i];

		if (z == y) continue;

		DFS(z, x);

		X[x].push_back(a[z]), A -= a[z];

		Y[x].push_back(b[z]), B -= b[z];

	}

	if (flag[x]) {

		X[x].push_back(A - 1);

		X[x].push_back(1);

		Y[x].push_back(B);

	}

	else {

		X[x].push_back(A);

		Y[x].push_back(B - 1);

		Y[x].push_back(1);

	}

}



int func(vector <int> &a) {

	int s = 0, t = 0;

	for (int i = 0; i < a.size(); i ++) {

		s = (s + a[i]) % mod;

		t = (t + 1ll * a[i] * a[i]) % mod;

	}

	s = 1ll * s * s % mod;

	s = (s - t + mod) % mod;

	return s;

}



int main() {

	//freopen("r.in", "r", stdin);

	scanf("%d", &n);

	for (int i = 1; i <= n; i ++) scanf("%d", &val[i]);

	for (int i = 1, x, y; i < n; i ++) scanf("%d %d", &x, &y), v[x].push_back(y), v[y].push_back(x);

	dfs(1, 0);

	for (int i = 1; i <= n; i ++) ans = (ans + val[i]) % mod;

	DFS(1, 0);

	for (int i = 1; i <= n; i ++) {

		if (flag[i]) ans = (ans + (1ll * val[i] * (func(X[i]) - func(Y[i])) % mod)) % mod;

		else ans = (ans - (1ll * val[i] * (func(X[i]) - func(Y[i])) % mod)) % mod;

	}

	ans = (ans + mod) % mod;

	printf("%d\n", ans);



	return 0;

}