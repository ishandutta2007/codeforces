#include <iostream>
#include <vector>
using namespace std;

int main() {
	int m, s;
	cin >> m >> s;
	int sum = 0;
	vector<int> nums;
	while (sum < s) {
		if (s-sum <= 9) {
			nums.push_back(s-sum);
			sum = s;
		}
		else {
			nums.push_back(9);
			sum+=9;
		}
	}
	// for (int i = 0; i < nums.size() ; i++) {
	// 	cout << nums[i] << " ";
	// }
	// cout << "   done" << endl;
	// cout <<"here" << endl;
	if (nums.size() > m || s == 0) {
		if (m == 1 && s == 0) cout << 0 << " " << 0 << endl;
		else cout << -1 << " " << -1 << endl;
	}
	else {
		if (nums.size() == m) {
			for (int i = m-1; i >= 0; i--) {
				cout << nums[i];
			}
		}
		else {
			cout << 1;
			nums[nums.size()-1]--;
			// cout << endl << m-1-nums.size() << endl;
			for (int i = 0; i < m-1-nums.size(); i++) {
				cout << 0;
			}
			for (int i = nums.size()-1; i >= 0; i--) {
				cout << nums[i];
			}
			nums[nums.size()-1]++;

		}
	
		cout << " ";
		for (int i = 0; i < nums.size(); i++) {
			cout << nums[i];
		}

		for (int i = 0; i < m-nums.size(); i++) {
			cout << 0;
		}
		cout << endl;
	}
	// cin >> m;
}