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

long long getRoot(long long n) {
	long long m = sqrt((double)(n));
	for (long long i = m - 1; i <= m + 1; ++i) {
		if (i * i == n) {
			return i;
		}
	}
	return -1;
}

vector < pair < long long, long long > > getCandidates(long long a) {
	long long d = a * a;
	vector < pair < long long, long long > > res;
	for (long long x = 0; x * x <= d; ++x) {
		long long y = getRoot(d - x * x);
		if (y == -1) {
			continue;
		}
		res.push_back(make_pair(x, y));
		res.push_back(make_pair(x, -y));
		res.push_back(make_pair(-x, y));
		res.push_back(make_pair(-x, -y));
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long a, b;
	cin >> a >> b;

	long long c = a * a + b * b;

	vector < pair < long long, long long > > u = getCandidates(a);
	vector < pair < long long, long long > > v = getCandidates(b);

	for (int i = 0; i < u.size(); ++i) {
		for (int j = 0; j < v.size(); ++j) {
			long long d = (u[i].first - v[j].first) * (u[i].first - v[j].first) + (u[i].second - v[j].second) * (u[i].second - v[j].second);
			if (c != d) {
				continue;
			}

			if (u[i].first == 0 || u[i].second == 0 || v[j].first == 0 || v[j].second == 0) {
				continue;
			}
			if (u[i].first == v[j].first || u[i].second == v[j].second) {
				continue;
			}
			cout << "YES" << endl;
			cout << "0 0" << endl;
			cout << u[i].first << " " << u[i].second << endl;
			cout << v[j].first << " " << v[j].second << endl;
			return 0;
		}
	}
	cout << "NO" << endl;

	return 0;
}