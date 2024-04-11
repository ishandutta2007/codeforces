#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
const int maxN = 1100;
int a[maxN];

int main() {
	// your code goes here
	cin >> n >> m;
	for (int i = 1; i <= 2 * n + 1; ++i) {
		cin >> a[i];
	}
	for (int i = 2; i <= 2 * n + 1; i += 2) {
		if (m > 0 && a[i] - 1 > max(a[i - 1], a[i + 1])) {
			--m;
			--a[i];
		}
	}
	for (int i = 1; i <= 2 * n + 1; ++i) {
		cout << a[i] << " ";
	}
	return 0;
}