#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> nums;

bool isprime[2000010];

// bool isprime(int u) {
// 	for (int i = 2; i * i <= u; i++) {
// 		if (u % i == 0) return false;
// 	}
// 	return true;
// }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int cur;
	for (int i = 1; i <= n; i++) {
		cin >> cur;
		nums.push_back(cur);
	}

	fill(isprime, isprime+2000005, true);

	for (int i = 2; i <= 2000000; i++) {
		if (isprime[i]) {
			for (int j = i + i; j <= 2000000; j += i) {
				isprime[j] = false;
			}
		}
	}

	// int res = 1;
	vector<int> ans;
	ans.push_back(nums[0]);

	vector<int> o1;
	bool ht = false;
	for (int i = 0; i < n; i++) {
		if (nums[i] == 1) o1.push_back(1);
		else if (!ht && isprime[nums[i]+1]) {
			ht = true;
			o1.push_back(nums[i]);
		}

	}

	if (o1.size() > ans.size()) {
		ans.clear();
		for (int v : o1) ans.push_back(v);
	}
	if (ans.size() >= 2) {
		cout << ans.size() << endl;
		for (int v : ans) {
			cout << v << " ";
		}
		cout << endl;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (isprime[nums[i]+nums[j]]) {
				ans.clear();
				ans.push_back(nums[i]);
				ans.push_back(nums[j]);
			}
		}
	}
	cout << ans.size() << endl;
	for (int v : ans) cout << v << " ";
		cout << endl;

}