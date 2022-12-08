#include <iostream>

using namespace std;

int main() {
	int n, c;
	int count = 0;
	int prev = 0;
	cin >> n >> c;
	int cur;
	for (int i = 0; i < n; ++i) {
		cin >> cur;
		if (cur - prev > c) count = 0;
		prev = cur;
		count++;
	}
	cout << count << endl;
	// cin >> n;
}