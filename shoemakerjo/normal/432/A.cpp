#include <iostream>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int count = 0;
	int cur;
	for (int i = 0; i < n; ++i) {
		cin >> cur;
		if (cur + k <= 5) count++;
	}
	int ans = count/3;
	cout << ans << endl;
}