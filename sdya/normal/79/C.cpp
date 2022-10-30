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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
const long long P = 137LL;
string s;
int n, m;
string b[maxN];
pair < long long, long long > h[maxN];
long long p[maxN];
bool w[11][maxN];

bool contains(pair < long long, long long > a) {
	for (int i = 0; i < m; ++i) {
		if (h[i] == a) {
			return true;
		}
	}
	return false;
}

void precalc() {
	p[0] = 1LL;
	for (int i = 1; i < maxN; ++i) {
		p[i] = p[i - 1] * P;
	}
	for (int i = 0; i < m; ++i) {
		long long hash = 0;
		for (int j = 0; j < b[i].size(); ++j) {
			hash = hash * P + (long long)(b[i][j]);
		}
		h[i] = make_pair(b[i].size(), hash);
	}

	for (int len = 1; len <= 10 && len <= n; ++len) {
		long long start = 0;
		for (int i = 0; i < len; ++i) {
			start = start * P + (long long)(s[i]);
		}
		for (int i = 0; i + len - 1 < n; ++i) {
			w[len][i] = contains(make_pair(len, start));
			if (i + len < n) {
				start = start * P + (long long)(s[i + len]);
				start -= (long long)(s[i]) * p[len];
			}
		}
	}
}

int check(int len) {
	if (len == 0) {
		return 0;
	}
	int cnt = 0;
	for (int i = 0; i < len; ++i) {
		for (int j = 1; j <= 10 && i + j - 1 < len; ++j) {
			cnt += w[j][i];
		}
	}

	for (int i = 0; i + len - 1 < n; ++i) {
		if (cnt == 0) {
			return i;
		}
		for (int j = 1; j <= 10 && i + j - 1 < i + len; ++j) {
			cnt -= w[j][i];
		}
		for (int j = 1; j <= 10; ++j) {
			if (i + len - j + 1 >= i + 1) {
				cnt += w[j][i + len - j + 1];
			}
		}
	}
	return -1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cin >> s;
	n = s.size();
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	precalc();

	int left_bound = 0, right_bound = n;
	while (right_bound - left_bound > 1) {
		int middle = (left_bound + right_bound) / 2;
		if (check(middle) != -1) {
			left_bound = middle;
		} else {
			right_bound = middle;
		}
	}

	if (check(right_bound) != -1) {
		cout << right_bound << " " << check(right_bound) << endl;
	} else if (check(left_bound) != -1) {
		cout << left_bound << " " << check(left_bound) << endl;
	}

	return 0;
}