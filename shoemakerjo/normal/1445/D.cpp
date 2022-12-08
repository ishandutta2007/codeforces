#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define pii pair<int, int>

const ll mod = 998244353;

int n;
const int maxn = 150010;

vector<int> nums;

ll modpow(ll a, ll b) {
	if (b == 0) return 1LL;
	if (b & 1) {
		ll cur = modpow(a, b-1LL);
		return (cur * a) % mod;
		
	}
	ll cur = modpow(a, b/2LL);
	return (cur*cur) % mod;
	
}

ll inv(ll a) {
	return modpow(a, mod-2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	ll res = 0LL;

	for (int i = 0; i < 2*n; i++) {
		int cur;
		cin >> cur;
		nums.push_back(cur);
	}
	sort(nums.begin(), nums.end());

	ll onesum = 0LL;
	for (int i = 0; i < n; i++) {
		onesum += 0-nums[i] + nums[i+n];
	}
	onesum %= mod;
	// cout << "onesum " << onesum << endl;
// 
	ll nsums = 0LL;
	ll nfact = 1LL;
	ll n2fact = 1LL;
	for (int i = 1; i <= n; i++) {
		nfact = nfact * i % mod;
	}
	for (int i = 1; i <= 2*n; i++) {
		n2fact = n2fact * i % mod;
	}
	// cout << n2fact << " " << nfact << endl;
	ll infact = inv(nfact);
	ll ctemp = nfact * infact % mod;
	// cout << " ctemp " << ctemp << " " << infact << endl;
	// cout << "inverse " << infact << endl;
	nsums = ((n2fact * infact % mod) * infact) % mod;

	res = (onesum * nsums) % mod;
	cout << res << endl;

	// cout << "random " << modpow(2, 998244343) << endl;

}