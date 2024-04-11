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

	int n, a, b, c;
	cin >> n >> a >> b >> c;
	if (b < a) {
		swap(a, b);
	}
	if (c < a) {
		swap(a, c);
	}
	if (c < b) {
		swap(b, c);
	}

	int res = 0;
	for (int i = 0; i * c <= n; ++i) {
		for (int j = 0; i * c + j * b <= n; ++j) {
			int rem = n - i * c - j * b;
			if (rem % a == 0) {
				res = max(res, i + j + rem / a);
			}
		}
	}
	cout << res << endl;


	return 0;
}