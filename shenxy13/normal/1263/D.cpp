#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct UFDS {
	vector<int> parent, rankof;
	vector<bool> done;
	UFDS(int n) {
		for (int i = 0; i < n; ++i) {
			parent.push_back(i);
			rankof.push_back(0);
			done.push_back(false);
		}
	}
	int find_parent(int i) {
		if (parent[i] == i) return i;
		return parent[i] = find_parent(parent[i]);
	}
	void union_set(int p, int q) {
		int pp = find_parent(p), pq = find_parent(q);
		if (pp == pq) return;
		if (rankof[pp] == rankof[pq]) ++rankof[pp];
		if (rankof[pp] > rankof[pq]) parent[pq] = pp;
		else parent[pp] = pq;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, ans = 0;
	cin >> n;
	UFDS mysets(n + 26);
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		for (char c: s) mysets.union_set(c - 'a', i + 26);
	}
	for (int i = 0; i < n; ++i) {
		int k = mysets.find_parent(i + 26);
		if (!mysets.done[k]) {
			mysets.done[k] = true;
			++ans;
		}
	}
	cout << ans;
	return 0;
}