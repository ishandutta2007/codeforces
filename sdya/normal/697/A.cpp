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

	int t, s, x;
	cin >> t >> s >> x;
	if (x == t) {
		cout << "YES" << endl;
		return 0;
	}

	if (x < t + s) {
		cout << "NO" << endl;
		return 0;
	}
	if ((x - t) % s < 2) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}