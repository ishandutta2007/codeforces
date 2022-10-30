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

string gcd(long long x, long long y) {
	long long x1 = 1, y1 = 0, b1 = x;
	long long x2 = 0, y2 = 1, b2 = y;
	string res;

	string s = "AB";
	while (b2) {
		long long q = b1 / b2;
		if (q > 0) {
			if (b1 - q * b2 == 0) {
				if (q - 1 > 0) {
					res += to_string(q - 1);
					res += s[0];
				}
			} else {
				res += to_string(q);
				res += s[0];
			}
		}
		b1 -= q * b2;
		x1 -= q * x2;
		y1 -= q * y2;
		swap(s[0], s[1]);
		swap(x1, x2);
		swap(y1, y2);
		swap(b1, b2);
	}
	if (b1 != 1) {
		return "Impossible";
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long x, y;
	cin >> x >> y;
	cout << gcd(x, y) << endl;



	return 0;
}