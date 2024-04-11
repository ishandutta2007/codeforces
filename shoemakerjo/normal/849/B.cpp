#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	double slope;
	bool both = false;
	bool ok = false;

	slope = nums[1]-nums[0];
	double int1, int2;
	int1 = nums[0];
	bool tempo = true;
	for (int i = 2; i < n; i++) {
		if (abs(slope*i + int1 - nums[i]) < 0.001) {
			continue;
		}
		else {
			if (both) {
				if (abs(slope*i + int2 - nums[i]) < 0.001) {
					continue;
				}
				else tempo = false;
			}
			else {
				both = true;
				int2 = nums[i] - slope*i;
			}

		}
	}
	if (!both) tempo = false;
	ok = ok || tempo;

	both = false;
	slope = (nums[2]-nums[0])/2.0;
	int1 = nums[0];
	tempo = true;
	for (int i = 0; i < n; i++) {
		if (abs(slope*i + int1 - nums[i]) < 0.001) {
			continue;
		}
		else {
			if (both) {
				if (abs(slope*i + int2 - nums[i]) < 0.001) {
					continue;
				}
				else tempo = false;
			}
			else {
				both = true;
				int2 = nums[i] - slope*i;
			}

		}
	}
	if (!both) tempo = false;
	ok = ok || tempo;

	both = false;
	slope = (nums[2]-nums[1])/1.0;
	int1 = nums[1] - slope*1.0;
	tempo = true;
	for (int i = 0; i < n; i++) {
		if (abs(slope*i + int1 - nums[i]) < 0.001) {
			continue;
		}
		else {
			if (both) {
				if (abs(slope*i + int2 - nums[i]) < 0.001) {
					continue;
				}
				else tempo = false;
			}
			else {
				both = true;
				int2 = nums[i] - slope*i;
			}

		}
	}
	if (!both) tempo = false;
	ok = ok || tempo;

	if (ok) cout << "Yes\n";
	else cout << "No\n";
	cin >> ok;
}