#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
const long long inf = 1000000000000000000LL;
int n;
int a[maxN], b[maxN];
vector < int > c[maxN];

int t[maxN];
long long s[maxN];

void update(int k, int delta) {
	for (int i = k; i < maxN; i |= (i + 1)) {
		t[i] += delta;
		s[i] += (long long)(delta) * (long long)(k);
	}
}

int get(int k) {
	int res = 0;
	for (int i = k; i >= 0; i = (i & (i + 1)) - 1) {
		res += t[i];
	}
	return res;
}

long long getSum(int k) {
	long long res = 0;
	for (int i = k; i >= 0; i = (i & (i + 1)) - 1) {
		res += s[i];
	}
	return res;
}

long long calc(int need) {
	int left_bound = 0, right_bound = maxN - 1;
	while (right_bound - left_bound > 1) {
		int middle = (left_bound + right_bound) / 2;

		int sum = get(middle);
		if (sum >= need) {
			right_bound = middle;
		} else {
			left_bound = middle;
		}
	}

	if (get(left_bound) >= need) {
		int left_over = get(left_bound) - need;
		return getSum(left_bound) - (long long)(left_over) * (long long)(left_bound);
	}
	if (get(right_bound) >= need) {
		int left_over = get(right_bound) - need;
		return getSum(right_bound) - (long long)(left_over) * (long long)(right_bound);
	}

	return inf;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		c[a[i]].push_back(b[i]);
	}

	for (int i = 0; i < maxN; ++i) {
		if (c[i].size() > 0) {
			sort(c[i].rbegin(), c[i].rend());
		}
	}

	long long cost = 0;
	for (int i = 0; i < n; ++i) {
		cost += b[i];
	}

	vector < int > candidates;
	for (int i = 1; i < maxN; ++i) {
		if (c[i].size() > 0) {
			candidates.push_back(i);
		}
	}

	long long res = cost;
	int votes = n;

	for (int i = 1; i < maxN; ++i) {
		if (candidates.size() == 0) {
			if (votes > i) {
				res = min(res, cost);
			}
			continue;
		}

		vector < int > n_candidates;
		for (int j = 0; j < candidates.size(); ++j) {
			int current = c[candidates[j]][i - 1];
			cost -= current;
			update(current, +1);
			--votes;

			if (c[candidates[j]].size() > i) {
				n_candidates.push_back(candidates[j]);
			}
		}

		candidates = n_candidates;

		if (votes > i) {
			res = min(res, cost);
		} else {
			res = min(res, cost + calc(i + 1 - votes));
		}
	}

	cout << res << endl;


	return 0;
}