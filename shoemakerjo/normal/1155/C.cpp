#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 300010;
ll nums[maxn];
ll ops[maxn];
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> ops[i];
	}
	ll cv = nums[2] - nums[1];
	for (int i = 2; i < n; i++) {
		cv =	__gcd(cv, nums[i+1]-nums[i]);
	}

	for (int i = 1; i <= m; i++) {
		if (cv % ops[i] == 0LL) {
			cout << "YES" << endl;
			cout << nums[1] << " " << i << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}