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

vector < int > cntA(10), cntB(10);
int n;

bool check(int m, string &a, string &b) {
	vector < int > cntA = ::cntA;
	vector < int > cntB = ::cntB;
	bool ok = false;
	for (int cnt0 = 0; cnt0 <= cntA[0] && !ok; ++cnt0) {
		if (cnt0 >= m) {
			a.clear();
			b.clear();
			for (int i = 0; i <= 9; ++i) {
				for (int j = 0; j < cntA[i]; ++j) {
					a += '0' + i;
					b += '0' + i;
				}
			}
			reverse(a.begin(), a.end());
			reverse(b.begin(), b.end());
			ok = true;
		}
		cntA[0] -= cnt0;
		cntB[0] -= cnt0;
		for (int i = 1; i <= 9 && !ok; ++i) {
			if (cntA[i] < 1 || cntB[(10 - i) % 10] < 1) {
				continue;
			}
			--cntA[i];
			--cntB[(10 - i) % 10];

			int cur = 0;
			for (int j = 0; j <= 9; ++j) {
				cur += min(cntA[j], cntB[9 - j]);
			}
			if (cnt0 + 1 + cur >= m) {
				a = "";
				b = "";

				for (int j = 0; j < cnt0; ++j) {
					a += '0';
					b += '0';
				}

				a += '0' + i;
				b += '0' + (10 - i) % 10;
				for (int j = 0; j <= 9; ++j) {
					for (int k = 0; k < min(cntA[j], cntB[9 - j]); ++k) {
						a += '0' + j;
						b += '0' + 9 - j;
					}
					int d = min(cntA[j], cntB[9 - j]);
					cntA[j] -= d;
					cntB[9 - j] -= d;
				}
				for (int j = 0; j <= 9; ++j) {
					for (int k = 0; k < cntA[j]; ++k) {
						a += '0' + j;
					}
					for (int k = 0; k < cntB[j]; ++k) {
						b += '0' + j;
					}
				}
				reverse(a.begin(), a.end());
				reverse(b.begin(), b.end());
				ok = true;
			}

			++cntA[i];
			++cntB[(10 - i) % 10];
		}
		cntA[0] += cnt0;
		cntB[0] += cnt0;
	}
	return ok;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string s;
	cin >> s;
	n = s.size();
	for (int i = 0; i < s.size(); ++i) {
		++cntA[s[i] - '0'];
		++cntB[s[i] - '0'];
	}

	int left_bound = 0, right_bound = n;
	string a, b;
	while (right_bound - left_bound > 1) {
		int middle = (left_bound + right_bound) / 2;
		if (check(middle, a, b)) {
			left_bound = middle;
		} else {
			right_bound = middle;
		}
	}

	if (check(right_bound, a, b)) {
		cout << a << endl;
		cout << b << endl;
	} else if (check(left_bound, a, b)) {
		cout << a << endl;
		cout << b << endl;
	} else {
		cout << s << endl;
		cout << s << endl;
	}

	return 0;
}