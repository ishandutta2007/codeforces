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

	int n, k;
	cin >> n >> k;
	int m = 240 - k;

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (m >= 5 * i) {
			++res;
			m -= 5 * i;
		}
	}

	cout << res << endl;


	return 0;
}