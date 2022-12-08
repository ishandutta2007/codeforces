#include <bits/stdc++.h>

using namespace std;

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int n;
	cin >> n;
	int nums[n];
	vector<int> ns;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		ns.push_back(nums[i]);
	}
	// map<int, int> getind;
	sort(ns.begin(), ns.end());
	for (int i = 0; i < n; i++) {
		int spot = lower_bound(ns.begin(), ns.end(), nums[i])-ns.begin();

		cout << ns[(spot+1)%n] << " " ;
	}
	cout << endl;
	cin >> n;

}