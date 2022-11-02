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
	int n, m;
	cin >> n >> m;
	vector < int > a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector < int > res(n);
	set < int > s;
	for (int i = n - 1; i >= 0; --i) {
		s.insert(a[i]);
		res[i] = s.size();
	}

	for (int i = 0; i < m; ++i) {
		int t;
		cin >> t;
		cout << res[t - 1] << endl;
	}


	return 0;
}