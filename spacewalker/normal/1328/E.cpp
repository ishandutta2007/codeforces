#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;
vector<int> st, ed, tpar;
int t = 0;

void getInfo(int v, int p) {
	st[v] = t++;
	tpar[v] = p;
	for (int ch : tree[v]) {
		if (ch != p) getInfo(ch, v);
	}
	ed[v] = t;
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	tree = vector<vector<int>>(n);
	tpar = st = ed = vector<int>(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		--a; --b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	getInfo(0, -1);
	for (int i = 0; i < n; ++i) {
//		printf("v %d par %d int %d %d\n", i, tpar[i], st[i], ed[i]);
	}
	for (int qta = 0; qta < m; ++qta) {
		int k; scanf("%d", &k);
		vector<int> vset(k);
		for (int i = 0; i < k; ++i) {
			scanf("%d", &vset[i]);
			vset[i]--;
			if (vset[i] != 0) vset[i] = tpar[vset[i]];
//			printf("q %d elem %d\n", qta, vset[i]);
		}
		int baseElem = vset[0];
		for (int i = 1; i < k; ++i) {
			if (ed[vset[i]] - st[vset[i]] < ed[baseElem] - st[baseElem]) baseElem = vset[i];
		}
		bool umbrella = true;
		for (int i = 0; i < k; ++i) {
			if (!(st[vset[i]] <= st[baseElem] && ed[baseElem] <= ed[vset[i]])) umbrella = false;
		}
		if (umbrella) printf("YES\n");
		else printf("NO\n");
	}
}