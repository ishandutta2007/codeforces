#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define maxn 1000001
int n;

int BIT[maxn];

void insert(int u) {
	while (u <= n) {
		// cout << u  << endl;
		BIT[u]++;
		u += u&(-u);
	}
}

int query(int u) {
	int ans = 0;
	while (u > 0) {

		ans += BIT[u];
		u -= u&(-u);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < maxn; i++) {
		BIT[i] = 0;
	}
	map<int, int> pos; //coordinate compression
	vector<int> nums;
	int a[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		nums.push_back(a[i]);
	}
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++) {
		pos[nums[i]] = i+1;
		// cout << nums[i] << " - " << pos[nums[i]] << endl;
	}
	ll forward[n+1];
	for (int i = 1; i <= n; i++) {
		int spot = pos[a[i]];
		// cout << i << "   -   " << spot << endl;
		forward[i] = (i-1)-query(spot);
		insert(spot);
	}
	for (int i = 0; i < maxn; i++) {
		BIT[i] = 0;
	}
	ll backward[n+1];
	for (int i = n; i>= 1; i--) {
		int spot = pos[a[i]];
		backward[i] = query(spot);
		insert(spot);
	}
	ll ans = 0LL;
	for (int i = 1; i <= n; i++) {
		ans += forward[i]*backward[i];
		// cout << forward[i] << " " << backward[i] << " " <<  ans << endl;
	}
	cout << ans << endl;
	// cin >> ans;
}