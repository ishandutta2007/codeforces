#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;

	int nums[n];
	int m;

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	cin >> m;
	int left[m];
	int right[m];
	for (int i = 0; i < m; i++) {
		cin >> left[i] >> right[i];
	}
	int last = 0;
	for (int i = 0; i < n; ++i) {
		last += nums[i];
	}

	int val = -1;
	for (int i = 0; i < m; ++i) {
//		cout << "here ";
//		cout << left[i] << " " << right[i] << " " << val;
		if (left[i] >= last) {
			if (val==-1) {
				val = left[i];
			}
			else {
				val = min(val, left[i]);
			}
		}
		else if (left[i] <= last && last <= right[i]) {
//			cout << "??";
			val = last;
			break;
		}
	}
//	cout << last << endl;
//	for (int i = 0; i < m; ++i) {
//		cout << left[i] << " " << right[i] << endl;
//	}
	cout << val << endl;

}