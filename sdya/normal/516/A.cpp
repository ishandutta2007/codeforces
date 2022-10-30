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

long long cnt[10];

vector < long long > c[10];

vector < int > res;

void rec(int v, vector < int > digits) {
	int s = 0;
	for (int i = 0; i < 10; ++i) {
		s += cnt[i];
	}
	if (cnt[7] > 0 && v < 7) {
		return;
	}
	if (cnt[5] > 0 && v < 5) {
		return;
	}
	if (cnt[3] > 0 && v < 3) {
		return;
	}
	if (s == 0) {
		if (digits.size() > res.size() || (digits.size() == res.size() && digits > res)) {
			res = digits;
		}
		return;
	}

	for (int i = v; i >= 2; --i) {
		bool isgood = true;
		for (int j = 2; j < 10; ++j) {
			cnt[j] -= c[i][j];
			if (cnt[j] < 0) {
				isgood = false;
			}
		}
		if (isgood) {
			digits.push_back(i);
			rec(i, digits);
			digits.pop_back();
		}
		for (int j = 2; j < 10; ++j) {
			cnt[j] += c[i][j];
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string s;
	int n;
	cin >> n;
	cin >> s;
	for (int i = 2; i <= 9; ++i) {
		c[i].resize(10);
		for (int j = 2; j <= i; ++j) {
			if (j == 4) {
				c[i][2] += 2;
			} else if (j == 6) {
				++c[i][2];
				++c[i][3];
			} else if (j == 8) {
				c[i][2] += 3;
			} else if (j == 9) {
				c[i][3] += 2;
			} else {
				++c[i][j];
			}
		}
	}
	for (int i = 0; i < s.size(); ++i) {
		int a = s[i] - '0';
		if (a > 1) {
			for (int j = 0; j < 10; ++j) {
				cnt[j] += c[a][j];
			}
		}
	}

	vector < int > a;
	rec(7, a);
	for (int i = 0; i < res.size(); ++i) {
		printf("%d", res[i]);
	}
	printf("\n");

	//cerr << clock() << endl;

	return 0;
}