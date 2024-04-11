#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a, c[3];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a, c[a]++;
	int ret = 0;
	for (int i = 0; i <= c[1] && i <= c[2]; i++) {
		ret = max(ret, i + (c[1] - i) / 3);
	}
	cout << ret << endl;
	return 0;
}