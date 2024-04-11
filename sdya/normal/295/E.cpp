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

const int maxN = 410000;
int n, x[maxN], y[maxN];
int m, mode[maxN], u[maxN], v[maxN];

struct State {
	long long score;
	long long s;
	long long cnt;
	State() {
		score = 0;
		s = 0;
		cnt = 0;
	}
	State(long long score, long long s, long long cnt) : score(score), s(s), cnt(cnt) {
	}

	void merge(const State &A, const State &B) {
		s = A.s + B.s;
		cnt = A.cnt + B.cnt;
		score = A.score + B.score + B.s * A.cnt - A.s * B.cnt;
	}
};

State t[4 * maxN];

void update(int i, int l, int r, int k, long long value, long long add) {
	if (l == r) {
		t[i].s += value;
		t[i].cnt += add;
		return ;
	}
	if (k > (l + r) / 2) {
		update(2 * i + 1, (l + r) / 2 + 1, r, k, value, add);
	} else {
		update(2 * i, l, (l + r) / 2, k, value, add);
	}
	t[i].merge(t[2 * i], t[2 * i + 1]);
}

State get(int i, int l, int r, int cl, int cr) {
	if (l == cl && r == cr) {
		return t[i];
	}
	if (cl > (l + r) / 2) {
		return get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
	}
	if (cr <= (l + r) / 2) {
		return get(2 * i, l, (l + r) / 2, cl, cr);
	}
	State A = get(2 * i, l, (l + r) / 2, cl, (l + r) / 2);
	State B = get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr);
	State res;
	res.merge(A, B);
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	vector < int > a;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x[i]);
		y[i] = x[i];
		a.push_back(x[i]);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &mode[i], &u[i], &v[i]);
		if (mode[i] == 1) {
			y[u[i]] += v[i];
			a.push_back(y[u[i]]);
		} else {
			a.push_back(u[i]);
			a.push_back(v[i]);
		}
	}
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());

	int s = a.size();

	for (int i = 1; i <= n; ++i) {
		int index = lower_bound(a.begin(), a.end(), x[i]) - a.begin();
		update(1, 0, s - 1, index, x[i], 1);
	}

	for (int i = 1; i <= m; ++i) {
		if (mode[i] == 1) {
			int index = lower_bound(a.begin(), a.end(), x[u[i]]) - a.begin();
			update(1, 0, s - 1, index, -x[u[i]], -1);

			x[u[i]] += v[i];
			index = lower_bound(a.begin(), a.end(), x[u[i]]) - a.begin();
			update(1, 0, s - 1, index, x[u[i]], +1);
		} else {
			int l = lower_bound(a.begin(), a.end(), u[i]) - a.begin();
			int r = lower_bound(a.begin(), a.end(), v[i]) - a.begin();
			State res = get(1, 0, s - 1, l, r);
			printf("%I64d\n", res.score);
		}
	}

	return 0;
}