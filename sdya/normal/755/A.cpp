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

const int maxN = 2000000;
bool p[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	p[1] = true;
	for (int i = 2; i * i < maxN; ++i) {
		if (p[i]) {
			continue;
		}
		for (int j = i * i; j < maxN; j += i) {
			p[j] = true;
		}
	}

	int n;
	cin >> n;
	for (int i = 1; i <= 1000; ++i) {
		if (p[n * i + 1]) {
			cout << i << endl;
			return 0;
		}
	}

	return 0;
}