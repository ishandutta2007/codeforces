#include <bits/stdc++.h>

using namespace std;

void deletePoint(int i, vector<int> &prv, vector<int> &nxt) {
	if (prv[i] != -1) nxt[prv[i]] = nxt[i];
	if (nxt[i] != -1) prv[nxt[i]] = prv[i];
}

void answer(bool b) {
	if (b) printf("YES\n");
	else printf("NO\n");
	exit(0);
}

struct SibuyasHanap {
	int n;
	vector<int> p;
	SibuyasHanap(int n) : n(n), p(n, -1) {}
	int hanap(int i) { return (p[i] < 0 ? i : p[i] = hanap(p[i])); }
	bool join(int i, int j) {
		i = hanap(i), j = hanap(j);
		if (i == j) return false;
		if (p[i] > p[j]) swap(i, j);
		p[i] += p[j]; p[j] = i;
		return true;
	}
};

int main() {
	int n; scanf("%d", &n);
	vector<pair<int, int>> intervals(n);
	for (int i = 0; i < n; ++i) scanf("%d %d", &intervals[i].first, &intervals[i].second);
	for (int i = 0; i < n; ++i) --intervals[i].first, --intervals[i].second;
	vector<pair<int, int>> elist;
	vector<int> prevIndex(2 * n, -1), nextIndex(2 * n, -1);
	vector<int> flatRep(2 * n);
	for (int i = 0; i < n; ++i) {
		flatRep[intervals[i].first] = i;
		flatRep[intervals[i].second] = i;
	}
	for (int i = 0; i + 1 < 2 * n; ++i) nextIndex[i] = i + 1;
	for (int i = 1; i < 2 * n; ++i) prevIndex[i] = i - 1;
	vector<int> procOrder(n);
	for (int i = 0; i < n; ++i) procOrder[i] = i;
	sort(begin(procOrder), end(procOrder), [&intervals] (int i, int j) {
		return (intervals[i].second - intervals[i].first) <= (intervals[j].second - intervals[i].first);
	});
	for (int x : procOrder) {
		for (int i = nextIndex[intervals[x].first]; i != intervals[x].second; i = nextIndex[i]) {
			elist.emplace_back(x, flatRep[i]);
		}
		deletePoint(intervals[x].first, prevIndex, nextIndex);
		deletePoint(intervals[x].second, prevIndex, nextIndex);
		if (elist.size() > n - 1) break;
	}
	if (elist.size() != n - 1) answer(false);
	SibuyasHanap cfing(n);
	for (auto u_v : elist) {
		if (!cfing.join(u_v.first, u_v.second)) answer(false);
	}
	answer(true);
	return 0;
}