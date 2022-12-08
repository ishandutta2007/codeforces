#include <bits/stdc++.h>

using namespace std;

int main() {
	int nums[7];
	for (int i =  0; i <  7; i++) {
		nums[i] = 0;
	}
	int n;
	cin >> n;
	string line;
	for (int i = 0; i  < n; i++) {
		cin >> line;
		for (int j = 0; j < 7; j++) {
			nums[j] += line[j]-'0';
		}
	}
	int ans = 0;
	for (int i = 0; i < 7; i++) {
		ans = max(ans, nums[i]);
	}
	cout << ans << endl;
	cin >> ans;
}