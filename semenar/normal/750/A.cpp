#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#define max(a, b) (a > b ? a : b)

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	int time = 240 - k;
	for (int i = 1; i <= n; i++) {
		if (time < 5 * i) {
			cout << i - 1 << endl;
			return 0;
		}
		time -= 5 * i;
	}
	cout << n << endl;
	return 0;
}