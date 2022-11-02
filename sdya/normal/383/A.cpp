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

const int maxN = 210000;
int a[maxN], n;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	int s = 0;
	long long res = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] == 0) {
			res += s;
		}
		s += (a[i] == 1);
	}
	cout << res << endl;

	return 0;
}