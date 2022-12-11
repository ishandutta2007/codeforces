#include <bits/stdc++.h>
using namespace std;

vector <int> from[30];
string res;

void dfs(int x) {
	while (from[x].size()) {
		int v = from[x].back(); from[x].pop_back();
		dfs(v);
		res.push_back(x + 'a');
	}
}

int main() {
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			from[i].push_back(j);
		}
	}
	dfs(0);
	while (res.size() < n) res += res;
	res.resize(n);
	printf("%s\n", res.c_str());
	return 0;
}