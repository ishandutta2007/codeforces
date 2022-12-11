#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = (1 << 20) + 1;

struct pair_hash
{
	template <class T1, class T2>
	std::size_t operator () (std::pair<T1, T2> const &pair) const
	{
		std::size_t h1 = std::hash<T1>()(pair.first);
		std::size_t h2 = std::hash<T2>()(pair.second);

		return h1 ^ h2;
	}
};

vector<pair<int, int>> arr[NMAX]; // (dest, edgeID)
vector<pair<int, bool>> knownEList; // (# on parts, is it backwards?)
vector<bool> existent; // is the edge present?
vector<bool> searchHit;
vector<int> edgesOnPath;

void getPath(int u) {
	while (!arr[u].empty()) {
		int v, eID; tie(v, eID) = *arr[u].rbegin();
		arr[u].pop_back();
		if (!existent[eID]) continue;
		existent[eID] = false;
		existent[eID ^ 1] = false;
		getPath(v);
		edgesOnPath.push_back(eID ^ 1);
	}
}

int main() {
	int n; scanf("%d", &n);
	vector<pair<int, int>> parts(n);
	for (int i = 0; i < n; ++i) scanf("%d %d", &parts[i].first, &parts[i].second);
	for (int i = 0; i < n; ++i) {
		knownEList.emplace_back(i, false);
		knownEList.emplace_back(i, true);
	}
	existent = vector<bool>(2 * n, true);
	edgesOnPath.reserve(2 * n);
	for (int attSize = 20; attSize > 0; --attSize) {
//		printf("attempting %d\n", attSize);
		for (int i = 0; i < 1 << attSize; ++i) arr[i].clear();
		int potStart = -1;
		for (int i = 0; i < knownEList.size(); i += 2) {
			int u = parts[i/2].first & (((1 << attSize) - 1)), v = parts[i/2].second & (((1 << attSize) - 1));
//			printf("EDGE %d %d\n", u, v);
			arr[u].emplace_back(v, i);
			arr[v].emplace_back(u, i + 1);
			potStart = u;
		}
		bool eulerian = true;
		for (int i = 0; i < (1 << attSize); ++i) if (arr[i].size() % 2 == 1) eulerian = false;
		if (!eulerian) continue;
		fill(begin(existent), end(existent), true);
		edgesOnPath.clear();
		searchHit = vector<bool>(1 << attSize, false);
		getPath(potStart);
		if (edgesOnPath.size() < n) continue;
		printf("%d\n", attSize);
		vector<int> ans;
		for (int e : edgesOnPath) {
//			printf("EDGE %d\n", e);
			int a = knownEList[e].first * 2, b = knownEList[e].first * 2 + 1;
			if (knownEList[e].second) swap(a, b);
			ans.push_back(a);
			ans.push_back(b);
		}
		for (int x : ans) printf("%d ", x + 1);
		printf("\n");
		return 0;
	}
	printf("0\n");
	for (int i = 1; i <= 2 * n; ++i) printf("%d ", i);
	printf("\n");
	return 0;
}