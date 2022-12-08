#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int nums[n];
	set<int> inc;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		inc.insert(nums[i]);
	}
	for (int i = n-1; i >= 0; i--) {
		if (inc.size() == 1) break;
		if (inc.find(nums[i]) != inc.end()) {
			inc.erase(inc.find(nums[i]));
		}
	}
	cout << *inc.begin() << endl;
	cin >> n;
}