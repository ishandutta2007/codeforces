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

	int n;
	cin >> n;
	long long x = 0;

	const int M = 20000;

	for (int i = 0; i < n; ++i) {
		long long d;
		string s;
		cin >> d >> s;
		if (x == 0 && s != "South") {
			printf("NO\n");
			return 0;
		}
		if (x == M && s != "North") {
			printf("NO\n");
			return 0;
		}
		if (s == "South") {
			x += d;
			if (x > M) {
				printf("NO\n");
				return 0;
			}
		}
		if (s == "North") {
			x -= d;
			if (x < 0) {
				printf("NO\n");
				return 0;
			}
		}
	}

	if (x == 0) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}


	return 0;
}