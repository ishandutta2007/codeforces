#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> magulang;
vector<vector<int>> anak;
vector<int> preorder;

void getPreorder(int v) {
	preorder.push_back(v);
	for (int nxt : anak[v]) getPreorder(nxt);
}

int main() {
	scanf("%d", &n);
	magulang = vector<int>(n, -1);
	anak = vector<vector<int>>(n);
	for (int i = 1; i < n; ++i) {
		scanf("%d", &magulang[i]);
		anak[magulang[i]].push_back(i);
	}
	vector<int> lalim(n);
	for (int i = 1; i < n; ++i) lalim[i] = lalim[magulang[i]] + 1;
	int protectRoot = 0;
	for (int i = 1; i < n; ++i) if (lalim[i] > lalim[protectRoot]) protectRoot = i;
	vector<bool> tanggol(n); 
	vector<int> nextLabel(n, -1), ans;
	for (int cv = protectRoot; cv != -1; cv = magulang[cv]) {
		tanggol[cv] = true;
		if (magulang[cv] != -1) nextLabel[magulang[cv]] = cv;
	}
//	printf("PR %d\n", protectRoot);
	getPreorder(0);
	for (int v : preorder) {
		if (tanggol[v]) continue;
		int sumusunod = nextLabel[magulang[v]];
		nextLabel[magulang[v]] = v;
//		printf("splicing %d into %d->%d\n", v, magulang[v], sumusunod);
		ans.push_back(sumusunod);
		nextLabel[v] = sumusunod;
	}
	for (int cx = 0; cx != -1; cx = nextLabel[cx]) printf("%d ", cx);
	printf("\n");
	printf("%lu\n", ans.size());
	reverse(begin(ans), end(ans));
	for (int x : ans) printf("%d ", x);
	printf("\n");
	return 0;
}