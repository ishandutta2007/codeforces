#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct IndexTree {
	int setCount;
	IndexTree *left, *right;
	int al, ar;
	IndexTree (int i, int j) : setCount(0), left(nullptr), right(nullptr), al(i), ar(j) {
		if (i != j) {
			int k = (i + j) / 2;
			left = new IndexTree(i, k);
			right = new IndexTree(k + 1, j);
		}
	}
	void addElem(int i) {
		if (i < al || ar < i) return;
		else ++setCount;
		if (al != ar) {
			left->addElem(i);
			right->addElem(i);
		}
	}
	int getAt(int i) {
		// zero-indexed
		if (al == ar) return al;
		else if (left->setCount > i) {
			return left->getAt(i);
		} else {
			return right->getAt(i - left->setCount);
		}
	}
};

struct event {
	ll t, x, y;
	event(ll t, ll x, ll y) : t(t), x(x), y(y) {}
	const bool operator < (event other) const {
		return (t != other.t ? t < other.t : y < other.y);
	}
};

int main() {
	int n, m, q; scanf("%d %d %d", &n, &m, &q);
	vector<int> start(m);
	for (int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		start[x-1]++;
	}
	vector<ll> queries(q);
	for (int i = 0; i < q; ++i) scanf("%lld", &queries[i]);
	for (int i = 0; i < q; ++i) queries[i] -= 1 + n;
	vector<int> queryOrder(q);
	for (int i = 0; i < q; ++i) queryOrder[i] = i;
	sort(begin(queryOrder), end(queryOrder), [&queries] (int i, int j) {
			return queries[i] < queries[j];
	});
	vector<int> startCount(n+1);
	for (int i = 0; i < m; ++i) {
//		printf("%d starts with %d\n", i, start[i]);
		startCount[start[i]]++;
	}
	vector<ll> minBoundAt(n+1); // at which time does the min hosting become >= i?
	int itemToFill = startCount[0]; // how many items do we iterate through?
	for (int i = 1; i <= n; ++i) {
//		printf("i %d itf %d\n", i, itemToFill);
		minBoundAt[i] = (minBoundAt[i-1] + itemToFill);
		itemToFill += startCount[i];
	}
//	for (int i = 0; i <= n; ++i) {
//		printf("%d mba %lld\n", i, minBoundAt[i]);
//	}
	// event type:
	// at time minBoundAt[start[i]], add city i to the eligible set (and add 1 to itf, reset lastadd)
	// at time q[i], check for the ith element
	vector<event> evts;
	for (int i = 0; i < m; ++i) {
		evts.emplace_back(minBoundAt[start[i]], i, -1);
	}
	for (int i = 0; i < q; ++i) {
		evts.emplace_back(queries[i], i, 1);
	}
	sort(begin(evts), end(evts));
	ll lastReset = 0;
	itemToFill = 0;
	IndexTree cfing(0, m-1);
	vector<int> qans(q);
	for (event evt : evts) {
		if (evt.y == -1) {
			// update
//			printf("update %d fighter %d\n", evt.t, evt.x);
			cfing.addElem(evt.x);
			++itemToFill;
			lastReset = evt.t;
		} else {
			int realIndex = (evt.t - lastReset) % itemToFill;
			qans[evt.x] = cfing.getAt(realIndex);
//			printf("query %d time %d RI %d\n", evt.x, evt.t, realIndex);
		}
	}
	for (int i = 0; i < q; ++i) {
		printf("%d\n", qans[i] + 1);
	}
	return 0;
}