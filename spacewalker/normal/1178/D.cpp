#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x) {
	for (int i = 2; i < x; ++i) {
		if (x % i == 0) return false;
	}
	return true;
}


int main() {
	int n; scanf("%d", &n);
	vector<pair<int, int>> edges;
	for (int i = 0; i < n; ++i) {
		edges.emplace_back(i, (i + 1) % n);	
	}
	for (int i = 0; !isPrime(edges.size()); ++i) {
		edges.emplace_back(i, i + n/2);
	}
	printf("%lu\n", edges.size());
	for (auto pp : edges) {
		printf("%d %d\n", pp.first + 1, pp.second + 1);
	}
	return 0;
}