#include <iostream>
using namespace std;
int d[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int n, m;
int main() {
	cin >> n >> m; n--, m--;
	cout << (d[n] + m - 1) / 7 - m / 7 + 1 << endl;
	return 0;
}