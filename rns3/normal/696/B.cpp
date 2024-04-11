#include <bits/stdc++.h>
using namespace std;

#define N 100100

vector <int> vec[N];
int n, p, si[N];
double e[N];

void Dfs(int u) {
	int sz = vec[u].size();
	si[u] = 1;
	if (!sz) return;
	for (int i = 0; i < sz; i ++) {
		Dfs(vec[u][i]);
        si[u] += si[vec[u][i]];
	}
}

void dfs(int u) {
	int sz = vec[u].size();
	if (!sz) return;
	if (sz == 1) {
		e[vec[u][0]] = e[u] + 1;
		dfs(vec[u][0]);
		return;
	}
	double now = e[u] + (si[u] - 1) / 2.0 + 1;
    for (int i = 0; i < sz; i ++) {
		e[vec[u][i]] = now - si[vec[u][i]] / 2.0;
		dfs(vec[u][i]);
    }
}

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i ++) {
		scanf("%d", &p);
		vec[p].push_back(i);
	}
	e[1] = 1;
	Dfs(1);
	dfs(1);
	for (int i = 1; i < n; i ++) printf("%lf ", e[i]);
	printf("%lf\n", e[n]);
	return 0;
}