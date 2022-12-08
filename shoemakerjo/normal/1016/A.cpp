#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	ll m;
	cin >> n >> m;
	//how many pages do i turn? ( how many finished pages are there)
	ll finpage = 0;
	ll tsum = 0;
	vector<ll> ans;
	ll cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		tsum += cur;
		ll cpage = tsum/m;
		ans.push_back(cpage - finpage);
		finpage = cpage;
	}
	for (ll val : ans) cout << val << " ";
	cout << endl;

}