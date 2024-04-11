#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const long long P = 257LL;
const int maxN = 1100000;
char s[maxN], t[maxN];
int p[maxN];
int n;

struct HashString {
	char s[maxN];
	long long ha[maxN];
	long long hb[maxN];
	long long pw[maxN];

	void set(char c[maxN]) {
		int n = strlen(c);
		memset(s, 0, sizeof(s));
		for (int i = 0; i < n; ++i) {
			s[i] = c[i];
		}
	}
	void calculateHashes() {
		pw[0] = 1LL;
		for (int i = 1; i < maxN; ++i) {
			pw[i] = pw[i - 1] * P;
		}

		int n = strlen(s);
		ha[0] = s[0];
		for (int i = 1; i < n; ++i) {
			ha[i] = ha[i - 1] * P + s[i];
		}

		hb[n - 1] = s[n - 1];
		for (int i = n - 2; i >= 0; --i) {
			hb[i] = hb[i + 1] * P + s[i];
		}
	}

	long long substr(int l, int r) {
		if (l > r) {
			return 0;
		}
		return ha[r] - (l == 0 ? 0 : (ha[l - 1] * pw[r - l + 1]));
	}

	long long substrR(int l, int r) {
		if (l > r) {
			return 0;
		}
		return hb[l] - hb[r + 1] * pw[r - l + 1];
	}
};

HashString S, T;

vector < int > a, b;

int getPos(int start) {
	int left_bound = start + 1, right_bound = n - 1;
	while (right_bound - left_bound > 1) {
		int middle = (left_bound + right_bound) / 2;
		if (S.substr(start + 1, middle - 1) == T.substr(0, middle - start - 2)) {
			left_bound = middle;
		} else {
			right_bound = middle;
		}
	}

	if (S.substr(start + 1, right_bound - 1) == T.substr(0, right_bound - start - 2)) {
		return right_bound - start - 1;
	}
	if (S.substr(start + 1, left_bound - 1) == T.substr(0, left_bound - start - 2)) {
		return left_bound - start - 1;
	}
	return 0;
}

int st[4 * maxN];

pair < int, int > get(int i, int l, int r, int cl, int cr, int bound) {
	if (l == cl && r == cr) {
		if (st[i] < bound) {
			return make_pair(l, -1);
		}
		if (l == r) {
			return make_pair(l, st[i]);
		}

		if (st[2 * i] >= bound) {
			return get(2 * i, l, (l + r) / 2, l, (l + r) / 2, bound);
		}
		return get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, r, bound);
	}

	if (cl > (l + r) / 2) {
		return get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr, bound);
	}
	if (cr <= (l + r) / 2) {
		return get(2 * i, l, (l + r) / 2, cl, cr, bound);
	}

	pair < int, int > A = get(2 * i, l, (l + r) / 2, cl, (l + r) / 2, bound);
	if (A.second >= bound) {
		return A;
	}
	return get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr, bound);
}

void build(int i, int l, int r) {
	if (l == r) {
		st[i] = p[l];
		return ;
	}

	build(2 * i, l, (l + r) / 2);
	build(2 * i + 1, (l + r) / 2 + 1, r);
	st[i] = max(st[2 * i], st[2 * i + 1]);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	gets(s);
	gets(t);

	n = strlen(s);
	if (n != strlen(t)) {
		cout << -1 << " " << -1 << endl;
		return 0;
	}

	S.set(s);
	T.set(t);

	S.calculateHashes();
	T.calculateHashes();

	for (int i = 0; i < n; ++i) {
		long long x = S.substrR(0, i);
		long long y = T.substr(n - 1 - i, n - 1);
		if (x == y) {
			a.push_back(i);
		}
	}

	for (int i = 0; i < n; ++i) {
		if (t[i] != s[n - 1]) {
			p[i] = -1;
			continue;
		}
		int left_bound = i, right_bound = n - 1;
		while (right_bound - left_bound > 1) {
			int middle = (left_bound + right_bound) / 2;
			if (T.substr(i, middle) == S.substrR(n - 1 - (middle - i), n - 1)) {
				left_bound = middle;
			} else {
				right_bound = middle;
			}
		}
		if (T.substr(i, right_bound) == S.substrR(n - 1 - (right_bound - i), n - 1)) {
			p[i] = right_bound;
		} else {
			p[i] = left_bound;
		}
	}

	build(1, 0, n - 1);

	int x = -1, y = -1;
	for (int start = 0; start + 1 < n; ++start) {
		if (!binary_search(a.begin(), a.end(), start)) {
			continue;
		}
		int finish = getPos(start);

		int bound = n - start - 2;
		pair < int, int > current = get(1, 0, n - 1, 0, finish, bound);
		if (current.second < bound) {
			continue;
		}
		x = start;
		y = x + current.first + 1;
	}

	cout << x << " " << y << endl;

	return 0;
}