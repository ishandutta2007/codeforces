#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int n, m, x, cnt[30009];
int main() {
	cin >> n >> m >> x;
	for (int i = n; i <= x; i += n) cnt[i]++;
	for (int i = m; i <= x; i += m) cnt[i]++;
	int ret = 0;
	for (int i = 1; i <= x; i++) {
		if (cnt[i] == 2) ret++;
	}
	cout << ret << endl;
	return 0;
}