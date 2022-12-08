#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	int most = 0, least = 0;
	int cur;
	map<int, long long> nums;
	for (int i = 0; i  < n; i++) {
		cin >> cur;
		if (i == 0) {
			most = cur;
			least = cur;
		}
		most = max(most, cur);
		least = min(least, cur);

		if (nums.count(cur) == 0) {
			nums[cur] = 1;
		}
		else nums[cur]++;
	}
	long long count = nums[most]*nums[least];
	if (most == least) {
		count = nums[most]*(nums[most]-1)/2;
	}
	cout << most-least << " " << count << endl;;
	// cin >> n;
}