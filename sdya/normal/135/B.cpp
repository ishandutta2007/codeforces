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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

long long dist(pair < int, int > a, pair < int, int > b) {
	long long dx = a.first - b.first;
	long long dy = a.second - b.second;
	return dx * dx + dy * dy;
}

bool isSquare(vector < pair < int, int > > a) {
	sort(a.begin(), a.end());
	do {
		bool ok = true;
		for (int i = 0; i + 1 < 4; ++i) {
			if (dist(a[i], a[i + 1]) != dist(a[0], a[3])) {
				ok = false;
				break;
			}
		}
		if (dist(a[0], a[2]) != 2LL * dist(a[0], a[1]) || dist(a[1], a[3]) != 2LL * dist(a[0], a[1])) {
			ok = false;
		}
		for (int i = 0; i < 4; ++i) {
			for (int j = i + 1; j < 4; ++j) {
				if (dist(a[i], a[j]) == 0) {
					ok = false;
				}
			}
		}
		if (ok) {
			return true;
		}
	} while (next_permutation(a.begin(), a.end()));
	return false;
}

bool isRectangle(vector < pair < int, int > > a) {
	sort(a.begin(), a.end());
	do {
		bool ok = true;
		if (dist(a[0], a[1]) != dist(a[2], a[3]) || dist(a[1], a[2]) != dist(a[0], a[3])) {
			ok = false;
		}
		if (dist(a[0], a[2]) != dist(a[1], a[3])) {
			ok = false;
		}

		for (int i = 0; i < 4; ++i) {
			for (int j = i + 1; j < 4; ++j) {
				if (dist(a[i], a[j]) == 0) {
					ok = false;
				}
			}
		}
		if (ok) {
			return true;
		}
	} while (next_permutation(a.begin(), a.end()));
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	vector < pair < int, int > > a(8);
	for (int i = 0; i < 8; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	for (int i = 0; i < (1 << 8); ++i) {
		vector < pair < int, int > > x, y;
		vector < int > u, v;
		for (int j = 0; j < 8; ++j) {
			if (i & (1 << j)) {
				x.push_back(a[j]);
				u.push_back(j + 1);
			} else {
				y.push_back(a[j]);
				v.push_back(j + 1);
			}
		}
		if (x.size() == 4 && isSquare(x) && isRectangle(y)) {
			cout << "YES" << endl;
			for (int j = 0; j < 4; ++j) {
				cout << u[j] << " ";
			}
			cout << endl;
			for (int j = 0; j < 4; ++j) {
				cout << v[j] << " ";
			}
			cout << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}