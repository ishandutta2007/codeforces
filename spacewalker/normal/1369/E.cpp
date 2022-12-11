#include <bits/stdc++.h>
#define kung if
#define para for
#define habang while
#define tumuloy continue

using namespace std;

int main() {
	int n, m; scanf("%d %d", &n, &m);
	vector<int> plato(n);
	for (int i = 0; i < n; ++i) scanf("%d", &plato[i]);
	vector<pair<int, int>> kaibigan(m);
	vector<int> gusto(n);
	vector<vector<int>> mayGustoSaPlato(n);
	for (int i = 0; i < m; ++i) {
		int x, y; scanf("%d %d", &x, &y);
		kaibigan[i] = {--x, --y};
		++gusto[x]; ++gusto[y];
		mayGustoSaPlato[x].push_back(i);
		mayGustoSaPlato[y].push_back(i);
	}
	queue<int> platongIhahain;
	for (int i = 0; i < n; ++i) if (gusto[i] <= plato[i]) platongIhahain.push(i);
	vector<int> sagot;
	vector<bool> nasaSagot(m);
	auto bawasan = [&platongIhahain, &gusto, &plato] (int i) {
		--gusto[i];
//		printf("plate %d has %d vs %d\n", i, gusto[i], plato[i]);
		if (gusto[i] <= plato[i]) platongIhahain.push(i);
	};
	habang (!platongIhahain.empty()) {
		int p = platongIhahain.front(); platongIhahain.pop();
		para (int tao : mayGustoSaPlato[p]) {
			kung (nasaSagot[tao]) tumuloy;
//			printf("removing %d [%d %d]\n", tao, kaibigan[tao].first, kaibigan[tao].second);
			sagot.push_back(tao);
			nasaSagot[tao] = true;
			bawasan(kaibigan[tao].first ^ kaibigan[tao].second ^ p);
		}
	}
	kung (sagot.size() < m) {
		printf("DEAD\n");
	} else {
		printf("ALIVE\n");
		reverse(begin(sagot), end(sagot));
		for (int x : sagot) printf("%d ", x + 1);
		printf("\n");
	}
	return 0;
}