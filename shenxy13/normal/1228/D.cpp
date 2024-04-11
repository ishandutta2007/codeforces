#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;
class UFDS {
	vector<int> parent, rankof;
	public:
		unordered_set<int> roots;
		UFDS(int N) {
			for (int i = 0; i < N; ++i) {
				parent.push_back(i);
				rankof.push_back(0);
				roots.insert(i);
			}
		}
		int find_parent(int x) {
			if (parent[x] == x) return x;
			return parent[x] = find_parent(parent[x]);
		}
		void union_set(int a, int b) {
			int pa = find_parent(a), pb = find_parent(b);
			if (pa == pb) return;
			if (rankof[pa] == rankof[pb]) {
				parent[pb] = pa;
				rankof[pa] += 1;
				roots.erase(pb);
			} else if (rankof[pa] > rankof[pb]) {
				parent[pb] = pa;
				roots.erase(pb);
			} else {
				parent[pa] = pb;
				roots.erase(pa);
			}
		}
};
int main() {
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	int colour[n], count[3];
	fill_n(colour, n, 0);
	fill_n(count, 3, 0);
	vector<int> adjlist[n];
	UFDS mysets(n);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		adjlist[a - 1].push_back(b - 1);
		adjlist[b - 1].push_back(a - 1);
		mysets.union_set(a - 1, b - 1);
	}
	if (mysets.roots.size() != 1) {
		printf("-1");
		return 0;
	}
	colour[0] = 1;
	count[0] += 1;
	for (int i: adjlist[0]) colour[i] = -1;
	for (int i = 1; i < n; ++i) {
		if (colour[i] != -1) {
			count[0] += 1;
			colour[i] = 1;
		}
	}
	int ne;
	for (ne = 0; ne < n && colour[ne] == 1; ++ne);
	if (ne == n) {
		printf("-1");
		return 0;
	}
	colour[ne] = 2;
	count[1] += 1;
	for (int i: adjlist[ne]) {
		if (colour[i] == -1) colour[i] = 3;
	}
	for (int i = 0; i < n; ++i) {
		if (colour[i] == -1) {
			count[1] += 1;
			colour[i] = 2;
		}
	}
	count[2] = n - count[0] - count[1];
	if (count[2] == 0) {
		printf("-1");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		for (int j: adjlist[i]) {
			if (colour[j] == colour[i]) {
				printf("-1");
				return 0;
			}
		}
		if (colour[i] == 1) {
			if (adjlist[i].size() != count[1] + count[2]) {
				printf("-1");
				return 0;
			}
		} else if (colour[i] == 2) {
			if (adjlist[i].size() != count[0] + count[2]) {
				printf("-1");
				return 0;
			}
		} else {
			if (adjlist[i].size() != count[0] + count[1]) {
				printf("-1");
				return 0;
			}
		}
	}
	for (int i: colour) printf("%d ", i);
	return 0;
}