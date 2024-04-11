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

const int maxN = 210000;
const long long inf = 1000000000000LL;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	long long l = -inf;
	long long r = inf;

	int n;
	scanf("%d", &n);
	long long added = 0;
	for (int i = 0; i < n; ++i) {
		int c, d;
		scanf("%d%d", &c, &d);
		if (d == 1) {
			l = max(l, 1900LL - added);
		} else {
			r = min(r, 1899LL - added);
		}
		added += (long long)(c);
	}

	if (l > r) {
		printf("Impossible\n");
		return 0;
	}
	if (r == inf) {
		printf("Infinity\n");
		return 0;
	}

	cout << r + added << endl;


	return 0;
}