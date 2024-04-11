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

inline int gcd(int a, int b) {
	while (b) {
		a %= b;
		swap (a, b);
	}
	return a;
}

const int maxL = 50000;
int even[maxL], p;

int solve2(int m, int k) {
	vector < int > odd;
	for (int i = 1; i <= m; ++i) {
		if (i % 2 == 1) {
			odd.push_back(i);
		} else {
			even[p++] = i / 2;
		}
	}

	vector < vector < int > > groups;
	for (int i = 0; i + 2 < odd.size(); i += 3) {
		vector < int > cur;
		cur.push_back(odd[i]);
		cur.push_back(odd[i + 1]);
		cur.push_back(odd[i + 2]);
		groups.push_back(cur);
	}

	int res = 0;
	for (int i = 0; i < groups.size(); ++i) {
		bool nice = false;
		int a = groups[i][0];
		int b = groups[i][1];
		int c = groups[i][2];
		int steps = 0;
		even[0] = (a + 1) / 2;
		even[1] = (c - 1) / 2;
		p = 2;
		for (int j = 0; j < p; ++j) {
			if (gcd(a, even[j]) == 1 && gcd(b, even[j]) == 1 && gcd(c, even[j]) == 1) {
				++res;
				printf("%d %d %d %d\n", a * k, b * k, c * k, even[j] * 2 * k);
				swap(even[j], even[p - 1]);
				--p;
				nice = true;
				break;
			}
		}
		if (!nice) {
			cerr << "FUCK" << endl;
		}
		//cerr << steps << endl;
	}
	return res;
}

int getPotential(int m) {
	int even = m / 2;
	int odd = m - even;
	return min(odd / 3, even);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	/*for (int i = 1; i <= 1000; ++i) {
		cerr << i << endl;
		cout << i << ": " << solve2(i) << ": " << getPotential(i) << endl;
	}*/

	int n, k;
	cin >> n >> k;

	for (int i = 1; ; ++i) {
		if (getPotential(i) == n) {
			printf("%d\n", i * k);
			solve2(i, k);
			break;
		}
	}

	//cerr << clock() << endl;

	return 0;
}