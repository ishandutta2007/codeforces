#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> nums;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i]=='2') nums.push_back(2);
		if (s[i]=='3') {
			nums.push_back(3);
		}
		if (s[i]=='4') {
			nums.push_back(3);
			nums.push_back(2);
			nums.push_back(2);
		}
		if (s[i] == '5') {
			nums.push_back(5);
		}
		if (s[i] == '6') {
			nums.push_back(5);
			nums.push_back(3);
		}
		if (s[i] == '7') {
			nums.push_back(7);
		}
		if (s[i] == '8') {
			nums.push_back(7);
			nums.push_back(2);
			nums.push_back(2);
			nums.push_back(2);
		}
		if (s[i] == '9') {
			nums.push_back(7);
			nums.push_back(3);
			nums.push_back(3);
			nums.push_back(2);
		}
	}
	sort(nums.begin(), nums.end());
	for (int i = nums.size()-1; i >= 0; i--) {
		cout << nums[i];
	}
	cout <<  endl;
	// cin >> n;
}