#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <stack>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210000;
const int maxD = 30;
const long long inf = 1000000000000000000LL;
int d, n, m;
pair < int, int > p[maxN];
long long dp[maxN];
int nt[maxN];

pair < int, int > t[4 * maxN];

void build(int i, int l, int r) {
	if (l == r) {
		t[i] = make_pair(p[l].second, l);
		return ;
	}
	build(2 * i, l, (l + r) / 2);
	build(2 * i + 1, (l + r) / 2 + 1, r);
	if (t[2 * i + 1].first <= t[2 * i].first) {
		t[i] = t[2 * i + 1];
	} else {
		t[i] = t[2 * i];
	}
}

pair < int, int > get(int i, int l, int r, int cl, int cr) {
	if (l == cl && r == cr) {
		return t[i];
	}
	if (cr <= (l + r) / 2) {
		return get(2 * i, l, (l + r) / 2, cl, cr);
	}
	if (cl > (l + r) / 2) {
		return get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
	}
	pair < int, int > A = get(2 * i, l, (l + r) / 2, cl, (l + r) / 2);
	pair < int, int > B = get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr);
	if (B.first <= A.first) {
		return B;
	}
	return A;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &d, &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &p[i].first, &p[i].second);
	}
	p[m++] = make_pair(0, 0);
	p[m++] = make_pair(d, 0);
	sort(p, p + m);
	build(1, 0, m - 1);

	for (int i = 0; i < m; ++i) {
		nt[i] = m - 1;
		if (i == m - 1) {
			continue;
		}
		int left_bound = i + 1, right_bound = m - 1;
		while (right_bound - left_bound > 1) {
			int middle = (left_bound + right_bound) / 2;
			pair < int, int > current = get(1, 0, m - 1, i + 1, middle);
			if (current.first <= p[i].second) {
				right_bound = middle;
			} else {
				left_bound = middle;
			}
		}
		if (get(1, 0, m - 1, i + 1, left_bound).first <= p[i].second) {
			nt[i] = left_bound;
		} else {
			nt[i] = right_bound;
		}
	}

	long long res = 0;
	int index = 0;
	int bound = 0;
	int rem = n;
	while (index != m - 1) {
		while (bound + 1 < m && p[index].first + n >= p[bound + 1].first) {
			++bound;
		}
		if (index == bound) {
			cout << -1 << endl;
			return 0;
		}
		pair < int, int > value = get(1, 0, m - 1, index + 1, bound);
		if (nt[index] <= bound && value.first <= p[index].second) {
			value = make_pair(p[nt[index]].second, nt[index]);
		}
		int i = value.second;
		int len = p[i].first - p[index].first;
		int needed = 0;
		if (rem < len) {
			needed = len - rem;
		}
		if (value.first > p[index].second) {
			needed = min(d - p[index].first, n - rem);
		}
		res += (long long)(needed) * (long long)(p[index].second);
		rem += needed - len;
		index = i;
	}
	cout << res << endl;


	return 0;
}