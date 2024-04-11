#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int n, x, y, dist[16777222];
int main() {
	dist[1] = 1;
	for (int i = 2; i <= 16777216; i++) {
		if (i % 2 == 0) dist[i] = dist[i / 2];
		if (i % 4 == 1) dist[i] = dist[i / 4] + 1;
		if (i % 4 == 3) dist[i] = dist[i / 4 + 1] + 1;
	}
	cin >> n >> x >> y;
	long long ret = 1LL << 60;
	for (int i = 0; i <= 24; i++) {
		int u = abs(n - (1 << i));
		int res = u >> i; u &= (1 << i) - 1;
		ret = min(ret, 1LL * (res + dist[u]) * x + 1LL * i * y);
	}
	cout << ret + x << endl;
	return 0;
}