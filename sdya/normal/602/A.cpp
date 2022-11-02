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

long long readNumber() {
	int n, b;
	scanf("%d%d", &n, &b);
	long long res = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		res *= b;
		res += x;
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long x = readNumber();
	long long y = readNumber();
	if (x < y) {
		cout << "<" << endl;
	} else if (x > y) {
		cout << ">" << endl;
	} else {
		cout << "=" << endl;
	}


	return 0;
}