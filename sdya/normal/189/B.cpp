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

	long long w, h;
	cin >> w >> h;
	long long res = 0;
	for (long long i = 1; i < w; ++i) {
		for (long long j = 1; j < h; ++j) {
			res += min(i, w - i) * min(j, h - j);
		}
	}
	cout << res << endl;


	return 0;
}