#include <bits/stdc++.h>

#define ll long long
#define maxn 200000

using namespace std;

int BIT[maxn+1];

ll query(int num) {
	ll ans = 0;
	while (num > 0) {
		ans += BIT[num];
		num -= num&(-num);
	}
	return ans;
}

void update(int num, int diff, int n) {
	while (num <= n) {
		BIT[num]+=diff;
		num += num&(-num);
	}
}

int main() {
	for (int i = 0; i <= maxn; i++) {
		BIT[i] = 0;
	}
	int n, q;
	cin >> n >> q;
	vector<ll> nums;
	ll cur;
	for  (int i = 1; i <= n; i++) {
		cin >> cur;
		nums.push_back(cur);
	}
	int l, r;
	for (int i = 0; i < q; i++) {
		cin >> l >> r;
		update(l, 1, n);
		update(r+1, -1, n);
	}
	ll ans = 0;
	sort(nums.begin(), nums.end());
	vector<ll> quants;
	for (int i = 1; i <= n; i++) {
		cur = query(i);
		// cout << "query: " << i << " " << cur << endl;
		quants.push_back(cur);
	}
	sort(quants.begin(), quants.end());
	for (int i = 0; i < n; i++) {
		ans += quants[i]*nums[i];
		// cout << ans << endl;
	}
	cout << ans << endl;
	cin >> n;
}