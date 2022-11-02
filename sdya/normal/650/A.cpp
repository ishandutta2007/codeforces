#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#include <ctime>
#include <unordered_set>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	map < int, int > x, y;
	map < pair < int, int >, int > p;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		++x[a];
		++y[b];
		++p[make_pair(a, b)];
	}

	long long res = 0;
	for (map < int, int > ::iterator it = x.begin(); it != x.end(); ++it) {
		long long n = it->second;
		res += n * (n - 1) / 2;
	}
	for (map < int, int > ::iterator it = y.begin(); it != y.end(); ++it) {
		long long n = it->second;
		res += n * (n - 1) / 2;
	}

	for (map < pair < int, int >, int > ::iterator it = p.begin(); it != p.end(); ++it) {
		long long n = it->second;
		res -= n * (n - 1) / 2;
	}

	cout << res << endl;


	return 0;
}