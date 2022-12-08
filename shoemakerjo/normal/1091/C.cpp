#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	vector<ll> ans;

	for (int i = 1; i *i <= n; i++) {
		if (n% i != 0) continue;
		int ofact = n/i;

		//have ofact of size i

		ll cur =  1LL * ofact;
		cur += ofact*(ofact-1LL)/2 * i;

		ans.push_back(cur);
		if (i == ofact) continue;
		cur = 1LL * i;
		cur += i*(i-1LL)/2 * ofact;
		ans.push_back(cur);
	}

	sort(ans.begin(), ans.end());
	for (ll val : ans) cout << val << " ";
		cout << endl;
}