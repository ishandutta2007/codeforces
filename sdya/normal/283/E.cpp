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
#include <stack>
#include <ctime>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int c[maxN];
int n, m;
int s[maxN];
int l[maxN], r[maxN];

int odd[4 * maxN], even[4 * maxN], add[4 * maxN];
int score[maxN];

void init(int i, int l, int r) {
	if (l == r) {
		even[i] = 1;
		return ;
	}
	init(2 * i, l, (l + r) / 2);
	init(2 * i + 1, (l + r) / 2 + 1, r);
	even[i] = r - l + 1;
}

void update(int i, int l, int r, int cl, int cr) {
	if (l == cl && r == cr) {
		add[i] ^= 1;
		swap(odd[i], even[i]);
		return ;
	}

	if (cl > (l + r) / 2) {
		update(2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
	} else if (cr <= (l + r) / 2) {
		update(2 * i, l, (l + r) / 2, cl, cr);
	} else {
		update(2 * i, l, (l + r) / 2, cl, (l + r) / 2);
		update(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr);
	}

	odd[i] = odd[2 * i] + odd[2 * i + 1];
	even[i] = even[2 * i] + even[2 * i + 1];
	if (add[i]) {
		swap(odd[i], even[i]);
	}
}

pair < int, int > get(int i, int l, int r, int cl, int cr) {
	if (cl > cr) {
		return make_pair(0, 0);
	}
	if (l == cl && r == cr) {
		pair < int, int > res = make_pair(even[i], odd[i]);
		return res;
	}
	pair < int, int > res;
	if (cl > (l + r) / 2) {
		res = get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
	} else if (cr <= (l + r) / 2) {
		res = get(2 * i, l, (l + r) / 2, cl, cr);
	} else {
		pair < int, int > a = get(2 * i, l, (l + r) / 2, cl, (l + r) / 2);
		pair < int, int > b = get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr);
		res = make_pair(a.first + b.first, a.second + b.second);
	}
	if (add[i]) {
		swap(res.first, res.second);
	}
	return res;
}

void build() {
	memset(odd, 0, sizeof(odd));
	memset(even, 0, sizeof(even));
	memset(add, 0, sizeof(add));
	init(1, 0, n - 1);
}

bool cmp(pair < int, int > a, pair < int, int > b) {
	return make_pair(a.second, a.first) > make_pair(b.second, b.first);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &s[i]);
	}
	sort(s, s + n);
	vector < pair < int, int > > p;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &l[i], &r[i]);
		int L = lower_bound(s, s + n, l[i]) - s;
		int R = upper_bound(s, s + n, r[i]) - s;
		if (L <= R - 1) {
			p.push_back(make_pair(L, R - 1));
		}
	}

	{
		sort(p.begin(), p.end());
		build();
		int index = 0;
		for (int i = 0; i < n; ++i) {
			while (index < p.size() && p[index].first <= i) {
				update(1, 0, n - 1, p[index].first, p[index].second);
				++index;
			}
			pair < int, int > current = get(1, 0, n - 1, i + 1, n - 1);
			score[i] += current.second;
		}
	}
	{
		sort(p.begin(), p.end(), cmp);
		build();
		int index = 0;
		for (int i = n - 1; i >= 0; --i) {
			while (index < p.size() && p[index].second >= i) {
				update(1, 0, n - 1, p[index].first, p[index].second);
				++index;
			}
			pair < int, int > current = get(1, 0, n - 1, 0, i - 1);
			score[i] += current.first;
		}
	}

	long long res = (long long)(n) * (long long)(n - 1) * (long long)(n - 2) / 6LL;
	for (int i = 0; i < n; ++i) {
		long long t = score[i];
		res -= (t * (t - 1)) / 2LL;
	}
	cout << res << endl;

	return 0;
}