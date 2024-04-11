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
	int n, d;
	cin >> n >> d;
	vector < int > a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int res = 0;
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		if (i >= n) {
			res -= d;
		} else {
			res += a[i];
		}
	}
	cout << res << endl;


	return 0;
}