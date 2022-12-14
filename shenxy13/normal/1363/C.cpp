#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, x, a, b;
vector<int> adjlist[1000];
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		scanf("%d %d", &n, &x);
		for (int i = 0; i < n; ++i) adjlist[i].clear();
		int u, v, turn = 0;
		a = b = 0, --x;
		for (int i = 1; i < n; ++i) {
			scanf("%d %d", &u, &v);
			adjlist[u - 1].push_back(v - 1);
			adjlist[v - 1].push_back(u - 1);
		}
		if (n == 1) {
			printf("Ayush\n");
			continue;
		}
		a = adjlist[x].size() + 1, b = n - a;
		while (a > 1) {
			if (a % 2 == 0) --a;
			else if (b != 0) --b;
			else --a;
			++turn;
		}
		printf(turn % 2 ? "Ayush\n" : "Ashish\n");
	}
	return 0;
}