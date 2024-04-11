#include <bits/stdc++.h>

using namespace std;

struct fenwick {
	int n;
	vector<int> tree;
	fenwick(int n) : n(n), tree(n + 1) {}
	fenwick(vector<int> &st) : n(st.size()), tree(st.size() + 1) {
		for (int i = 0; i < n; ++i) add(i, st[i]);
	}
	fenwick() {}
	int LSB(int i) {return (i & (-i));}
	void add(int i, int v) {
		for (int ci = i + 1; ci <= n; ci += LSB(ci)) tree[ci] += v;	
	}
	int getPrefixSum(int i) {
		int ans = 0;
		for (int ci = i + 1; ci > 0; ci -= LSB(ci)) ans += tree[ci];
		return ans;
	}
	int getRangeSum(int i, int j) {
		return getPrefixSum(j) - getPrefixSum(i - 1);
	}
	int getElem(int i) {
		return getRangeSum(i, i);
	}
};

struct ForceTree {
	set<pair<int, int>> forcePositions;
	fenwick flipCount;
	int n;
	ForceTree() {}
	// 0 is irrel, 1 is flip
	ForceTree(vector<int> arr): flipCount(arr), n(arr.size()) { }
	int predictOutcome(int start) {
		// Returns -1 or 1
		// Find the first
		int rangeStart = 0;
		if (!forcePositions.empty()) {
			tie(rangeStart, start) = *forcePositions.rbegin();
		}
		return start * (flipCount.getRangeSum(rangeStart, n - 1) % 2 == 0 ? 1 : - 1);
	}
	void setForce(int i, int fv) {
		if (flipCount.getElem(i) == 1) {
			flipCount.add(i, -1);
		}
		forcePositions.emplace(i, fv);
	}
};

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	vector<int> arr(n), bound(q);
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	vector<char> comp(q);
	for (int i = 0; i < q; ++i) scanf(" %c %d", &comp[i], &bound[i]);
	vector<pair<int, pair<int, int>>> evts; // 1 = change to FP, 2 = change to FN, 3 = evaluate
	vector<int> startingCond(q);
	for (int i = 0; i < q; ++i) {
		if (comp[i] == '<') {
			if (bound[i] >= 0) {
//				printf("%d start flip\n", i);
				startingCond[i] = 1;
				evts.emplace_back(bound[i], make_pair(1, i));
			} else {
				evts.emplace_back(-bound[i] + 1, make_pair(1, i));
			}
		} else {
			if (bound[i] < 0) {
//				printf("%d start flip\n", i);
				startingCond[i] = 1;
				evts.emplace_back(-bound[i], make_pair(2, i));
			} else {
				evts.emplace_back(bound[i] + 1, make_pair(2, i));
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (arr[i] != 0) evts.emplace_back(abs(arr[i]), make_pair(3, 69));
	}
	sort(begin(evts), end(evts));
	ForceTree yeeter(startingCond);
	map<int, int> ans;
	ans[0] = 0;
	for (auto evt : evts) {
//		printf("evt %d %d %d\n", evt.first, evt.second.first, evt.second.second);
		if (evt.second.first == 1) {
			yeeter.setForce(evt.second.second, 1);
		} else if (evt.second.first == 2) {
			yeeter.setForce(evt.second.second, -1);
		} else if (evt.first > 0) {
			ans[evt.first] = evt.first * yeeter.predictOutcome(1);
			ans[-evt.first] = (evt.first) * yeeter.predictOutcome(-1);
		}
	}
	for (int x : arr) printf("%d ", ans[x]);
	printf("\n");
	return 0;
}