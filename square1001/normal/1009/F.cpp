#include <cstdio>
#include <vector>
using namespace std;
int n; vector<int> ans, rans; vector<vector<int> > g, d;
int solve(int pos, int pre) {
	vector<int> childs;
	for (int i : g[pos]) {
		if (i != pre) childs.push_back(i);
	}
	int m = childs.size();
	vector<int> ptr(m);
	int mx = 0, mptr = -1;
	for (int i = 0; i < m; ++i) {
		ptr[i] = solve(childs[i], pos);
		if (mx < d[ptr[i]].size()) {
			mx = d[ptr[i]].size();
			mptr = i;
		}
	}
	int cptr = (m == 0 ? pos : ptr[mptr]);
	int least = mx;
	for (int i = 0; i < m; ++i) {
		if (i == mptr) continue;
		for (int j = 0; j < d[ptr[i]].size(); ++j) {
			d[cptr][mx - d[ptr[i]].size() + j] += d[ptr[i]][j];
		}
		if (least > mx - d[ptr[i]].size()) {
			least = mx - d[ptr[i]].size();
		}
	}
	ans[pos] = (m == 0 ? 0 : ans[childs[mptr]]);
	d[cptr].push_back(1);
	int cur = d[cptr][ans[pos]];
	for (int i = least; i <= mx; ++i) {
		if (cur <= d[cptr][i]) {
			cur = d[cptr][i];
			ans[pos] = i;
		}
	}
	rans[pos] = d[cptr].size() - ans[pos] - 1;
	return cptr;
}
int main() {
	scanf("%d", &n);
	g.resize(n);
	d.resize(n);
	ans.resize(n);
	rans.resize(n);
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	solve(0, -1);
	for (int i = 0; i < n; ++i) {
		printf("%d\n", rans[i]);
	}
	return 0;
}