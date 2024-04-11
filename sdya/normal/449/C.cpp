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
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int gcd (int a, int b) {
	while (b) {
		a %= b;
		swap (a, b);
	}
	return a;
}

const int maxN = 110000;
bool p[maxN];

int sodd[maxN], m;
bool used[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 2; i <= n; ++i) {
		if (!p[i]) {
			for (int j = i + i; j <= n; j += i) {
				p[j] = true;
			}
		}
	}

	vector < pair < int, int > > res;

	unordered_set < int > even;
	for (int i = 2; i <= n; i += 2) {
		even.insert(i);
	}

	unordered_set < int > odd;
	for (int i = 3; i <= n; i += 2) {
		if (!p[i] && i + i > n) {
			continue;
		}
		if (!p[i] && i + i + i > n) {
			even.erase(i + i);
			res.push_back(make_pair(i, i + i));
			continue;
		}
		sodd[m++] = i;
		odd.insert(i);
	}
		
	reverse(sodd, sodd + m);
	
	int total = 0;

	for (int i = n / 2; i >= 3; --i) {
		if (p[i]) {
			continue;
		}

		vector < int > c;
		for (int j = i; j <= n; j += 2 * i) {
			if (odd.count(j)) {
				c.push_back(j);
			}
		}
		reverse(c.begin(), c.end());
		for (int i = 0; i + 1 < c.size(); i += 2) {
			res.push_back(make_pair(c[i], c[i + 1]));
			odd.erase(c[i]);
			odd.erase(c[i + 1]);
		}
	}

	m = 0;
	while (!odd.empty()) {
		sodd[m ++] = *odd.begin();
		odd.erase(odd.begin());
	}
	sort(sodd, sodd + m);
	reverse(sodd, sodd + m);

	for (int i = 0; i < m; ++i) {
		if (used[i]) {
			continue;
		}
		bool good = false;
		for (int j = i + 1; j < m; ++j) {
			if (!used[j] && gcd(sodd[i], sodd[j]) > 1) {
				res.push_back(make_pair(sodd[i], sodd[j]));
				used[j] = true;
				++total;
				good = true;
				break;
			}
		}
		if (good) {
			used[i] = true;
		} else {
			if (even.count(sodd[i] * 2)) {
				res.push_back(make_pair(sodd[i], sodd[i] * 2));
				even.erase(sodd[i] * 2);
			} else {
				cerr << "s: " << sodd[i] << endl;
			}
		}
	}

	while (even.size() > 1) {
		int value = *even.begin();
		even.erase(even.begin());
		int v2 = *even.begin();
		even.erase(even.begin());
		res.push_back(make_pair(value, v2));
	}

	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); ++i) {
		printf("%d %d\n", res[i].first, res[i].second);
	}

	cerr << clock() << endl;
	//cerr << total << endl;

	return 0;
}