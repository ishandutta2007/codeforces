#define _CRT_SECURE_NO_WARNINGS
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
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 50;
const int maxL = 10000000;
int n;
int d[maxN];

map < vector < int >, bool > M;

bool solve(const vector < int > &s);

vector < int > combine(const vector < int > &a, int value) {
	vector < int > res;
	bool f = true;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] <= value) {
			res.push_back(a[i]);
		} else {
			if (f) {
				res.push_back(value);
				f = false;
			}
			res.push_back(a[i]);
		}
	}
	if (f) {
		res.push_back(value);
	}
	return res;
}

bool rec(const vector < pair < int, int > > &s, vector < int > &t, int index, int needed, int total, int cnt = 0) {
	if (index == s.size()) {
		if (needed == 0 && cnt >= 2) {
			return solve(combine(t, total));
		}
		return false;
	}

	for (int i = 0; i <= s[index].second; ++i) {
		if (s[index].first * i > needed) {
			break;
		}
		for (int j = 0; j < s[index].second - i; ++j) {
			t.push_back(s[index].first);
		}
		if (rec(s, t, index + 1, needed - i * s[index].first, total, cnt + i)) {
			return true;
		}
		for (int j = 0; j < s[index].second - i; ++j) {
			t.pop_back();
		}
	}
	return false;
}

bool solve(const vector < int > &s) {
	if (M.count(s)) {
		return M[s];
	}

	int total = 0;
	for (int i = 0; i < s.size(); ++i) {
		total += s[i];
	}
	if (total == n && s.size() == 1) {
		return M[s] = true;
	}
	if (total == n && s.size() > 1) {
		return M[s] = false;
	}

	vector < pair < int, int > > b;
	int current = s[0];
	int cnt = 1;
	for (int i = 1; i <= s.size(); ++i) {
		if (i == s.size() || s[i] > s[i - 1]) {
			b.push_back(make_pair(current, cnt));
			cnt = 1;
			if (i < s.size()) {
				current = s[i];
			}
		} else {
			++cnt;
		}
	}
	vector < int > t;
	if (d[total] == 2) {
		return false;
	}
	if (rec(b, t, 0, d[total] - 1, d[total])) {
		return M[s] = true;
	}
	return M[s] = false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &d[i]);
	}
	sort(d, d + n);

	vector < int > start;
	for (int i = 0; i < n; ++i) {
		if (d[i] == 1) {
			start.push_back(1);
		}
	}
	if (solve(start)) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}

	return 0;
}