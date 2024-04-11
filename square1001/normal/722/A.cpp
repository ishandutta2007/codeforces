#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n; string s;
string func(int a, int b) {
	string r1 = to_string(a);
	string r2 = to_string(b);
	while (r1.size() < 2) r1 = '0' + r1;
	while (r2.size() < 2) r2 = '0' + r2;
	r1 += ':' + r2;
	return r1;
}
int solve(int a, int b) {
	string r = func(a, b);
	int ret = 0;
	for (int i = 0; i < 5; i++) ret += (r[i] != s[i] ? 1 : 0);
	return ret;
}
int main() {
	cin >> n >> s;
	string ret; int v = 999999999;
	for (int i = (n == 12 ? 1 : 0); i <= (n == 12 ? 12 : 23); i++) {
		for (int j = 0; j < 60; j++) {
			if (solve(i, j) < v) {
				v = solve(i, j);
				ret = func(i, j);
			}
		}
	}
	cout << ret << endl;
	return 0;
}