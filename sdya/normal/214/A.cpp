#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
const int maxN = 1100;
int a[maxN];

int main() {
	// your code goes here
	cin >> n >> m;
	int res = 0;
	for (int a = 0; a <= n; ++a) {
		for (int b = 0; b <= m; ++b) {
			if (a * a + b == n && a + b * b == m) {
				++res;
			}
		}
	}
	cout << res << endl;
	return 0;
}