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

const int maxN = 110;
long long n, m, k;
long long a[maxN], b[maxN], c[maxN];
long long start[maxN];

map < pair < pair < int, int >, long long >, long long > M;
map < pair < pair < int, int >, long long >, pair < int, long long > > parent;

long long calc(int s, int index, long long value) {
	if (M.count(make_pair(make_pair(s, index), value))) {
		return M[make_pair(make_pair(s, index), value)];
	}

	long long res = -1;
	if (s == 1) {
		return M[make_pair(make_pair(s, index), value)] = value;
	}
	for (int i = 1; i <= m; ++i) {
		if (c[i] > c[index] && value + k >= a[i] && value + k <= b[i]) {
			long long score = calc(s - 1, i, value + k);
			if (score != -1) {
				score += value;
				if (score > res) {
					res = score;
					parent[make_pair(make_pair(s, index), value)] = make_pair(i, value + k);
				}
			}
		}

		if (c[i] > c[index] && value * k >= a[i] && value * k <= b[i]) {
			long long score = calc(s - 1, i, value * k);
			if (score != -1) {
				score += value;
				if (score > res) {
					res = score;
					parent[make_pair(make_pair(s, index), value)] = make_pair(i, value * k);
				}
			}
		}
	}
	return M[make_pair(make_pair(s, index), value)] = res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		cin >> a[i] >> b[i] >> c[i];
	}

	long long best = -1;
	long long index, value;
	for (int i = m; i >= 1; --i) {
		for (long long j = a[i]; j <= b[i]; ++j) {
			long long score = calc(n, i, j);
			if (score > best) {
				best = score;
				index = i;
				value = j;
			}
		}
	}

	if (best == -1) {
		cout << "NO" << endl;
		return 0;
	}

	int x = n;
	int y = index;
	long long z = value;
	vector < pair < int, long long > > res;
	while (x != 0) {
		res.push_back(make_pair(y, z));
		pair < int, long long > p = parent[make_pair(make_pair(x, y), z)];
		y = p.first;
		z = p.second;
		--x;
	}

	cout << "YES" << endl;
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i].first << " " << res[i].second << endl;
	}

	return 0;
}