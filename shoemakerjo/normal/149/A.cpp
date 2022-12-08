#include <iostream>
#include <algorithm>
#include <array>
using namespace std;
 int main() {
 	int k;
 	cin >> k;
 	int nums[12];
 	for (int i = 0; i < 12; ++i) {
 		cin >> nums[i];
 	}
 	sort(begin(nums), end(nums));
 	int count = 0;
 	int sum = 0;
 	for (int i = 11; i >=0; --i) {
 		if (sum >= k) break;
 		sum+=nums[i];
 		count++;
 		if (sum >= k) break;
 	}
 	if (sum < k) {
 		cout << -1 << endl;
 	}
 	else cout << count << endl;
 	// cin >> k;
 }