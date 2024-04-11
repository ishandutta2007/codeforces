#include <iostream>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;
	int nums[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> nums[i][j];
		}
	}
	bool ok = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (nums[i][j]==1) continue;
			set<int> row;
			bool temp = false;
			for (int k = 0; k < n; k++) {
				row.insert(nums[i][k]);
			}
			for (int k = 0; k < n; k++) {
				if (row.find(nums[i][j]-nums[k][j]) != row.end()) {
					temp = true;
					break;
				}
			}
			if (!temp) ok = false;
		}
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	cin >> n;
	
}