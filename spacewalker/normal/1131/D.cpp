#include <bits/stdc++.h>

using namespace std;

struct ufds {
	int n;
	vector<int> p;
	ufds(int n) : n(n), p(n, -1) {}
	int rep(int i) {return (p[i] < 0 ? i : p[i] = rep(p[i]));}
	void join(int i, int j) {
		i = rep(i), j = rep(j);
		if (i == j) return;
		if (p[i] > p[j]) swap(i, j);
		p[i] += p[j], p[j] = i;
	}
};	

char eval[1010][1010];

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", eval[i]);
	}
	ufds equals(n + m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (eval[i][j] == '=') equals.join(i, n + j);
		}
	}
	vector<vector<int>> geqs(n + m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (eval[i][j] == '>') geqs[equals.rep(n + j)].push_back(equals.rep(i));
			else if (eval[i][j] == '<') geqs[equals.rep(i)].push_back(equals.rep(n + j));
		}
	}
	vector<int> topos;
	vector<int> iDeg(n + m);
	queue<int> toClear;
	vector<vector<int>> revgeq(n + m);
	for (int i = 0; i < n + m; ++i) {
		for (int j : geqs[i]) {
			++iDeg[j];
			revgeq[j].push_back(i);
		}
	}
	for (int i = 0; i < n + m; ++i) if (iDeg[i] == 0) toClear.push(i);
	while (!toClear.empty()) {
		int cur = toClear.front(); toClear.pop();
		topos.push_back(cur);
		for (int next : geqs[cur]) {
			--iDeg[next];
			if (iDeg[next] == 0) toClear.push(next);
		}
	}
	if (topos.size() != n + m) {
		printf("No\n");
		return 0;
	}
	vector<int> value(n + m);
	for (int v : topos) {
		for (int pred : revgeq[v]) value[v] = max(value[v], value[pred]);
		++value[v];
	}
	printf("Yes\n");
	for (int i = 0; i < n; ++i) {
		printf("%d ", value[equals.rep(i)]);
	} 
	printf("\n");
	for (int i = 0; i < m; ++i) {
		printf("%d ", value[equals.rep(i + n)]);
	} 
	printf("\n");
	return 0;
}