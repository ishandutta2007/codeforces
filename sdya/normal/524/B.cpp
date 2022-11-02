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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100;
const int inf = 2000000000;
int n, w[maxN], h[maxN];

int solve(int H) {
	int W = 0;
	for (int i = 0; i < n; ++i) {
		if (w[i] > H && h[i] > H) {
			return inf;
		}
		int best = max(w[i], h[i]);
		if (w[i] <= H) {
			best = min(best, h[i]);
		}
		if (h[i] <= H) {
			best = min(best, w[i]);
		}
		W += best;
	}
	return W * H;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> w[i] >> h[i];
	}

	int res = inf;
	for (int i = 0; i < n; ++i) {
		res = min(res, solve(h[i]));
		res = min(res, solve(w[i]));
	}

	cout << res << endl;

	return 0;
}