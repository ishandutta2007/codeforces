#include <bits/stdc++.h>

using namespace std;



#define N 101010



vector <int> v[N];



int sz[N], n;



void dfs(int x, int y) {

	sz[x] = 1;

	for (int i = 0; i < v[x].size(); i ++) {

		int z = v[x][i];

		if (z == y) continue;

		dfs(z, x);

		sz[x] += sz[z];

	}

}



int main() {

	//freopen("r.in", "r", stdin);

	scanf("%d", &n);

	for (int i = 1, x, y; i < n; i ++) {

		scanf("%d %d", &x, &y);

		v[x].push_back(y);

		v[y].push_back(x);

	}

	if (n & 1) {

		puts("-1");

		return 0;

	}

	dfs(1, 0);

	int rlt = 0;

	for (int i = 2; i <= n; i ++) if (sz[i] % 2 == 0) rlt ++;

	printf("%d\n", rlt);



	return 0;

}