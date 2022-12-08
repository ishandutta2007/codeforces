#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	string line;
	cin >> line;
	int nums[n+1];
	int start[26];
	int end[26];
	for (int i = 0; i <= n; i++) {
		nums[i] = 0;
	}
	for (int i = 0; i < 26; i++) {
		start[i] = -1;
		end[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		int num = line[i]-'A';
		if (start[num] >= 0) {
			nums[end[num]]++;
			end[num] = i+1;
			nums[i+1]--;
		}
		else {
			start[num] = i;
			end[num] = i+1;
			nums[i]++;
			nums[i+1]--;
		}
	}
	int ans = 0;
	int cur = 0;
	for (int i = 0; i < n+1; i++) {
		cur+=nums[i];
		ans = max(ans, cur);
	}
	if (ans > k) cout << "YES" << endl;
	else cout << "NO" << endl;
	// cin >> n;
}