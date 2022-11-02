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
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 2100;
int n, k;
int a[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	reverse(a, a + n);

	int res = 0;
	for (int i = 0; i < n; i += k) {
		res += 2 * (a[i] - 1);
	}

	cout << res << endl;


	return 0;
}