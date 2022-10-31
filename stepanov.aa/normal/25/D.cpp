//this task is from https://codeforces.com/contest/25/problem/D

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class DSU {
	vector<int> tree;
	vector<int> sizes;

public:

	DSU(int n) : tree(n), sizes(n, 1) {
		for (int i = 0; i < n; ++i) {
			tree[i] = i;
		}
	}


	int find_set(int v) {
		if (tree[v] == v) {
			return v;
		}
		else {
			int lider = find_set(tree[v]);
			tree[v] = lider;
			return lider;
		}
	}


	bool is_leader(int v) {
		return tree[v] == v;
	}


	bool union_sets(int v1, int v2) {
		/*
			returns true if v1 and v2are in the same sets,
			else retruns false
		*/
		int l1 = find_set(v1);
		int l2 = find_set(v2);
		if (l1 == l2) {
			return true;
		}
		else {
			if (sizes[l1] < sizes[l2]) {
				swap(l1, l2);
			}
			tree[l2] = l1;
			sizes[l1] += sizes[l2];
			return false;
		}
	}

};


int main() {
	int n;
	cin >> n;
	DSU ways(n);
	vector<pair<int, int>> ways_to_delete;
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		if (ways.union_sets(x, y)) {
			ways_to_delete.push_back({x, y});
		}
	}
	cout << ways_to_delete.size() << "\n";
	int last_leader = -1;
	int del_ways_count = 0;
	for (int i = 0; i < n; ++i) {
		if (ways.is_leader(i)) {
			if (last_leader != -1) {
				cout << ways_to_delete[del_ways_count].first + 1 << " " << ways_to_delete[del_ways_count++].second + 1 << " " <<
					last_leader + 1 << " " << i + 1  << "\n";
			}
			last_leader = i;
		}
	}
}