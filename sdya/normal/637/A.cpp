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

const int maxN = 1100;
int n, a[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int res = 0, id = -1;
	for (int i = n - 1; i >= 0; --i) {
		int cnt = 0;
		for (int j = i; j >= 0; --j) {
			if (a[j] == a[i]) {
				++cnt;
			}
		}
		if (cnt >= res) {
			res = cnt;
			id = a[i];
		}
	}
	cout << id << endl;

	return 0;
}