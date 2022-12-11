#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

pair<int, int> regularVersion(pair<int, int> a) {
	int cdiv = abs(gcd(a.first, a.second));
	return make_pair(a.first / cdiv, a.second / cdiv);
}

struct fenwick {
	int n;
	vector<int> tree;
	fenwick(int n) : n(n), tree(n + 1) {}
	int LSB(int i) {return (i&(-i));}
	void add(int i, int v) {
		for (int ci = i + 1; ci <= n; ci += LSB(ci)) tree[ci] += v;
	}
	int prefixSum(int i) {
		int ans = 0;
		for (int ci = i + 1; ci > 0; ci -= LSB(ci)) ans += tree[ci];
		return ans;
	}
	int rangeSum(int i, int j) {
		return prefixSum(j) - prefixSum(i - 1);
	}
};

int main() {
	int n; scanf("%d", &n);
	vector<pair<int, int>> normalized;
	vector<int> polyst(n), polyed(n);
	for (int i = 0; i < n; ++i) {
		polyst[i] = normalized.size();
		int k; scanf("%d", &k);
		vector<pair<int, int>> vs;
		for (int j = 0; j < k; ++j) {
			int xj, yj; scanf("%d %d", &xj, &yj);
			vs.emplace_back(xj, yj);
		}
		vs.push_back(vs[0]);
		vector<pair<int, int>> diffs(k);
		for (int j = 0; j < k; ++j) {
			diffs[j].first = (vs[(j + 1)].first - vs[j].first);
			diffs[j].second = (vs[(j + 1)].second - vs[j].second);
			diffs[j] = regularVersion(diffs[j]);
		}
		normalized.insert(end(normalized), begin(diffs), end(diffs));
		polyed[i] = normalized.size() - 1;
	}
	int k = normalized.size();
	int q; scanf("%d", &q);
	vector<pair<int, int>> qs;
	for (int i = 0; i < q; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		qs.emplace_back(--a, --b);
	}
	vector<int> qaOrder(q), answers(q);
	for (int i = 0; i < q; ++i) qaOrder[i] = i;
	sort(begin(qaOrder), end(qaOrder), [&qs] (int i, int j) {return qs[i] < qs[j];});
	fenwick firstOccs(k);
	vector<int> nextCopy(k, -1);
	map<pair<int, int>, int> firstCopies;
	for (int i = k - 1; i >= 0; --i) {
		if (firstCopies.count(normalized[i]) > 0) nextCopy[i] = firstCopies[normalized[i]];
		firstCopies[normalized[i]] = i;
	}
	for (auto pp : firstCopies) firstOccs.add(pp.second, 1);
	int headerElem = 0;
	for (int qta : qaOrder) {
//		printf("answering range %d to %d\n", polyst[qs[qta].first], polyed[qs[qta].second]);
		while (headerElem < polyst[qs[qta].first]) {
//			printf("moving past elem %d\n", headerElem);
			if (nextCopy[headerElem] != -1) firstOccs.add(nextCopy[headerElem], 1);
			headerElem++;
//			printf("header now %d %d\n", headerElem, polyst[qs[qta].first]);
		}
		answers[qta] = firstOccs.rangeSum(polyst[qs[qta].first], polyed[qs[qta].second]);
	}
	for (int v : answers) printf("%d\n", v);
	return 0;
}