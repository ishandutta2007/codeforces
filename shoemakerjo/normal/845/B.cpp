#include <bits/stdc++.h>

using namespace std;

int main() {
	string dig; cin >> dig;
	int nums[6];
	for (int i = 0; i < 6; i++) {
		nums[i] = dig[i] -'0';
	}
	int lsum = nums[0]+nums[1]+nums[2];
	int rsum = nums[3]+nums[4]+nums[5];
	if (lsum == rsum) cout << 0 << endl;
	else {
		bool done = false;
		for (int i = 0; i < 3; i++) {
			if (done) break;
			int temp = rsum-(lsum-nums[i]);
			if (temp >= 0 && temp <= 9) {
				done = true;
				cout << 1 << endl;
			}
		}
		for (int i = 0; i < 3; i++) {
			if (done) break;
			int temp = lsum-(rsum-nums[i+3]);
			if (temp >= 0 && temp <= 9) {
				done = true;
				cout << 1 << endl;
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j) continue;
				if (done) break;
				int temp = rsum-(lsum-nums[i]-nums[j]);
				if (temp >= 0 && temp <= 18) {
					done  = true;
					cout << 2 << endl;
				}
			}
		}
		for (int i = 3; i  < 6; i++) {
			for (int j = 3; j < 6; j++) {
				if (i == j) continue;
				if (done) break;
				int temp = lsum-(rsum-nums[i]-nums[j]);
				if (temp >= 0 && temp <= 18) {
					cout << 2 << endl;
					done = true;
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 3; j < 6; j++) {
				if (done) break;
				int temp = abs((lsum-nums[i])- (rsum-nums[j]));
				if (temp <= 9) {
					done = true;
					cout << 2 << endl;
				}
			}
		}
		if (!done) cout << 3 << endl;
	}
	cin >> nums[0];
}