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

int getDigits(int n) {
	int res = 0;
	while (n) {
		++res;
		n /= 7;
	}
	return max(res, 1);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	int u = getDigits(n - 1);
	int v = getDigits(m - 1);
	int digits = u + v;
	if (digits > 7) {
		printf("0\n");
		return 0;
	}

	set < pair < int, int > > S;
	vector < int > order;
	for (int i = 0; i < 7; ++i) {
		order.push_back(i);
	}

	do {
		int a = 0;
		for (int i = 0; i < u; ++i) {
			a = a * 7 + order[i];
		}
		int b = 0;
		for (int i = u; i < u + v; ++i) {
			b = b * 7 + order[i];
		}
		if (a < n && b < m) {
			S.insert(make_pair(a, b));
		}
	} while (next_permutation(order.begin(), order.end()));

	cout << S.size() << endl;

	return 0;
}