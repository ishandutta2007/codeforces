#include <bits/stdc++.h>

using namespace std;

int n;
const int maxn = 1000010;
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

void gosmall() {
	vector<int> nums;
	int cur;
	for (int i = 1; i <= n; i++) {
		cout << "? " << i << endl;
		cin >> cur;
		nums.push_back(cur);
	}
	sort(nums.begin(), nums.end());
	cout << "! " << nums[0] << " " << nums[1]-nums[0] << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	srand(time(0));
	cin >> n;

	if (n <= 60) {
		gosmall();
		return 0;
	}

	int lo = 0, hi = 1000000000;
	int numleft = 60;
	while (lo < hi) {
		numleft--;
		int mid = (lo + hi)/2;
		cout << "> " << mid << endl;
		int res;
		cin >> res;
		if (res == 0) {
			hi = mid;
		}
		else lo = mid+1;
	}

	vector<int> nums;
	for (int i = 1; i <= n; i++) {
		nums.push_back(i);
	}
	for (int i = nums.size()-1; i >= 0; i--) {
		swap(nums[i], nums[rng32() %(i+1)]);
	}

	vector<int> vals;
	int cur;
	for (int i = 1; i <= numleft; i++) {
		cout << "? " << nums[i] << endl;
		cin >> cur;
		vals.push_back(cur);
	}
	sort(vals.begin(), vals.end());
	if (vals.back() != lo) vals.push_back(lo);


	int cd = vals[1]-vals[0];
	for (int i = 2; i < vals.size(); i++) {
		cd = __gcd(cd, vals[i]-vals[i-1]);
	}

	cout << "! " << lo - cd * (n-1) << " " << cd << endl;
}