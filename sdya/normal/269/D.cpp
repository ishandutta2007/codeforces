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

const int maxN = 310000;
int n, T;
int l[maxN], r[maxN], h[maxN];
vector < int > x;

int getId(int n) {
	return lower_bound(x.begin(), x.end(), n) - x.begin();
}

int tmin[4 * maxN];
int tmax[4 * maxN];
int s[4 * maxN];

void push(int i, int l, int r) {
	if (l == r) {
		if (s[i] != -1) {
			tmin[i] = s[i];
			tmax[i] = s[i];
			s[i] = -1;
		}
		return ;
	}
	if (s[i] != -1) {
		tmin[2 * i] = tmax[2 * i] = s[i];
		s[2 * i] = s[i];
		tmin[2 * i + 1] = tmax[2 * i + 1] = s[i];
		s[2 * i + 1] = s[i];
		tmin[i] = tmax[i] = s[i];
		s[i] = -1;
	}
}

void update(int i, int l, int r, int cl, int cr, int value) {
	push(i, l, r);
	if (l == cl && r == cr) {
		s[i] = value;
		tmin[i] = tmax[i] = value;
		return ;
	}
	if (cl > (l + r) / 2) {
		update(2 * i + 1, (l + r) / 2 + 1, r, cl, cr, value);
	} else if (cr <= (l + r) / 2) {
		update(2 * i, l, (l + r) / 2, cl, cr, value);
	} else {
		update(2 * i, l, (l + r) / 2, cl, (l + r) / 2, value);
		update(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr, value);
	}
	tmin[i] = min(tmin[2 * i], tmin[2 * i + 1]);
	tmax[i] = max(tmax[2 * i], tmax[2 * i + 1]);
}

pair < int, int > get(int i, int l, int r, int cl, int cr) {
	push(i, l, r);
	if (l == cl && r == cr) {
		return make_pair(tmin[i], tmax[i]);
	}
	pair < int, int > res;
	if (cl > (l + r) / 2) {
		res = get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
	} else if (cr <= (l + r) / 2) {
		res = get(2 * i, l, (l + r) / 2, cl, cr);
	} else {
		res = get(2 * i, l, (l + r) / 2, cl, (l + r) / 2);
		pair < int, int > buf = get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr);
		res.first = min(res.first, buf.first);
		res.second = max(res.second, buf.second);
	}
	tmin[i] = min(tmin[2 * i], tmin[2 * i + 1]);
	tmax[i] = max(tmax[2 * i], tmax[2 * i + 1]);
	return res;
}

int getLast(int i, int l, int r, int k, int value) {
	push(i, l, r);
	if (l == r) {
		if (tmin[i] == value) {
			return l;
		} else {
			return -1;
		}
	}
	int res = -1;
	if (k > (l + r) / 2) {
		res = getLast(2 * i + 1, (l + r) / 2 + 1, r, k, value);
	} else if (k >= l) {
		res = getLast(2 * i, l, (l + r) / 2, k, value);
		if (res == (l + r) / 2) {
			int current = getLast(2 * i + 1, (l + r) / 2 + 1, r, k, value);
			if (current != -1) {
				res = current;
			}
		}
	} else {
		if (tmin[2 * i] != value || tmax[2 * i] != value) {
			res = getLast(2 * i, l, (l + r) / 2, k, value);
		} else {
			res = (l + r) / 2;
			int current = getLast(2 * i + 1, (l + r) / 2 + 1, r, k, value);
			if (current != -1) {
				res = current;
			}
		}
	}
	tmin[i] = min(tmin[2 * i], tmin[2 * i + 1]);
	tmax[i] = max(tmax[2 * i], tmax[2 * i + 1]);
	return res;
}

int dp[maxN];

vector < pair < int, int > > getParents(int id) {
	int start = l[id];
	int finish = r[id] - 1;
	pair < int, int > current = get(1, 0, x.size() - 1, start, start);
	vector < pair < int, int > > ids;
	while (start <= finish) {
		int bound = min(finish, getLast(1, 0, x.size() - 1, start, current.first));
		if (current.first != -1) {
			ids.push_back(make_pair(current.first, bound - start));
		}
		start = bound + 1;
		if (start <= finish) {
			current = get(1, 0, x.size() - 1, start, start);
		}
	}
	return ids;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &T);
	
	x.push_back(-1000000000);
	x.push_back(1000000000);

	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &h[i], &l[i], &r[i]);
		x.push_back(l[i]);
		x.push_back(r[i]);
	}

	sort(x.begin(), x.end());
	x.resize(unique(x.begin(), x.end()) - x.begin());

	for (int i = 1; i <= n; ++i) {
		l[i] = getId(l[i]);
		r[i] = getId(r[i]);
	}

	l[0] = getId(-1000000000);
	r[0] = getId(1000000000);
	l[n + 1] = l[0];
	r[n + 1] = r[0];

	vector < pair < int, int > > order;
	for (int i = 1; i <= n; ++i) {
		order.push_back(make_pair(h[i], i));
	}
	order.push_back(make_pair(T, 0));
	order.push_back(make_pair(0, n + 1));
	sort(order.begin(), order.end());
	reverse(order.begin(), order.end());
	memset(s, -1, sizeof(s));
	update(1, 0, x.size() - 1, l[0], r[0] - 1, 0);

	dp[0] = 2000000000;
	for (int i = 1; i < order.size(); ++i) {
		int id = order[i].second;
		vector < pair < int, int > > parents = getParents(id);
		for (int j = 0; j < parents.size(); ++j) {
			int v = parents[j].first;
			int length = parents[j].second;

			int L = max(l[id], l[v]);
			int R = min(r[id] - 1, r[v] - 1);
			if (R - L == length && L <= R) {
				int trueLength = x[R + 1] - x[L];
				dp[id] = max(dp[id], min(dp[v], trueLength));
			}
		}
		update(1, 0, x.size() - 1, l[id], r[id] - 1, id);
	}

	printf("%d\n", dp[n + 1]);

	return 0;
}