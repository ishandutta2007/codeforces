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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector < int > a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int l = 0, r = n - 1;
	int b[2] = {0, 0};
	int move = 0;
	while (l <= r) {
		if (a[l] > a[r]) {
			b[move] += a[l++];
		} else {
			b[move] += a[r--];
		}
		move = 1 - move;
	}
	cout << b[0] << " " << b[1] << endl;


	return 0;
}