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

	int n, k;
	cin >> n >> k;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		vector < int > used(10, 0);
		int x;
		cin >> x;
		while (x) {
			used[x % 10] = 1;
			x /= 10;
		}
		bool isOk = true;
		for (int j = 0; j <= k; ++j) {
			if (used[j] == 0) {
				isOk = false;
			}
		}
		cnt += (int)(isOk);
	}
	cout << cnt << endl;



	return 0;
}