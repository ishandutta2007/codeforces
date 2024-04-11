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

string s;

bool isValid(int a, int b, int left) {
	return a + left >= b && a <= b + left;
}

bool isOk(int cnt4, int cnt7, int start) {
	int needed = s.size() / 2;
	cnt4 = needed - cnt4;
	cnt7 = needed - cnt7;
	for (int i = start; i < s.size(); ++i) {
		if (cnt7 > 0) {
			if (s[i] < '7') {
				return true;
			}
			if (s[i] > '7') {
				return false;
			}
			--cnt7;
		} else {
			if (s[i] < '4') {
				return true;
			}
			if (s[i] > '4') {
				return false;
			}
			--cnt4;
		}
	}
	return true;
}

string build(string s) {
	int n = s.size();
	if (n % 2 != 0) {
		return "";
	}
	string res = "";
	char a = '4';
	char b = '7';

	bool isOnPrefix = true;
	int cnt4 = 0, cnt7 = 0;
	for (int i = 0; i < n; ++i) {
		if (!isOnPrefix) {
			if (isValid(cnt4 + 1, cnt7, n - i - 1)) {
				res += a;
				++cnt4;
				continue;
			} 
			if (isValid(cnt4, cnt7 + 1, n - i - 1)) {
				res += b;
				++cnt7;
				continue;
			}
			return "";
		} else {
			if (a > s[i]) {
				if (isValid(cnt4 + 1, cnt7, n - i - 1)) {
					res += a;
					++cnt4;
					isOnPrefix = false;
					continue;
				}
				if (isValid(cnt4, cnt7 + 1, n - i - 1)) {
					res += b;
					++cnt7;
					isOnPrefix = false;
					continue;
				}
				return "";
			}
			if (a < s[i] && s[i] < b) {
				if (isValid(cnt4, cnt7 + 1, n - i - 1)) {
					res += b;
					++cnt7;
					isOnPrefix = false;
					continue;
				}
				return "";
			}
			if (s[i] > b) {
				return "";
			}

			if (s[i] == b) {
				if (isValid(cnt4, cnt7 + 1, n - i - 1)) {
					res += b;
					++cnt7;
					continue;
				}
				return "";
			}

			if (a == s[i]) {
				if (isValid(cnt4 + 1, cnt7, n - i - 1)) {
					if (isOk(cnt4 + 1, cnt7, i + 1)) {
						res += a;
						++cnt4;
						continue;
					}
				}

				if (isValid(cnt4, cnt7 + 1, n - i - 1)) {
					res += b;
					++cnt7;
					isOnPrefix = false;
					continue;
				}
				return "";
			}
		}
	}
	if (cnt4 == cnt7) {
		return res;
	}
	return "";
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> s;
	string res = build(s);
	if (res.size() == 0) {
		int length = s.size();
		++length;
		while (length % 2 != 0) {
			++length;
		}
		for (int i = 0; i < length; ++i) {
			printf("%c", (i >= length / 2) ? '7' : '4');
		}
		printf("\n");
		return 0;
	} else {
		cout << res << endl;
	}
	
	return 0;
}