#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int max;
	int min;
	int cur;
	int count = 0;
	for (int i = 0; i < n; ++i) {
		cin >> cur;
		if (i == 0) {
			max = cur;
			min = cur;
			continue;
		}
		if (cur > max) {
			count++;
			max = cur;
		}
		else if (cur < min) {
			count++;
			min = cur;
		}
	}
	cout << count << endl;
}