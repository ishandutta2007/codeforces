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

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, d;
	cin >> n >> d;
	int res = 0;
	int best = 0;
	for (int i = 0; i < d; ++i) {
		string s;
		cin >> s;
		if (count(s.begin(), s.end(), '1') == s.size()) {
			res = 0;
		} else {
			++res;
		}
		best = max(best, res);
	}

	cout << best << endl;


	return 0;
}