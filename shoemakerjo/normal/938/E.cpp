#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define maxn 1000010

const int mod = 1000000007;
ll facts[maxn];
ll ifacts[maxn];

ll raise(ll base, int exp) {
	if (exp == 0) return 1LL;
	if (exp == 1) return base;
	if (exp & 1) {
		ll tempo = raise(base, exp-1);
		tempo = (tempo*base)%mod;
		return tempo;
	}
	ll tempo = raise(base, exp/2);
	tempo = (tempo*tempo)%mod;
	return tempo;
}

ll inv(ll base) {
	return raise(base, mod-2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	facts[0] = 1LL;
	ifacts[0] = 1LL;
	for (int i = 1; i  <= n; i++) {
		facts[i] = (facts[i-1]*(i+0LL))%mod;
		ifacts[i] = inv(facts[i]);
	}
	vector<ll> nums;
	ll cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		nums.push_back(cur);
	}
	sort(nums.begin(), nums.end());
	int prevo = -1;
	int bef = 0;
	ll ans = 0LL;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == nums[nums.size()-1]) break;
		if (nums[i] != prevo) {
			prevo = nums[i];
			bef = i;

		}
		ll addon = (facts[n-bef-1]*facts[bef])%mod;
		addon = (addon*facts[n])%mod;
		addon = (addon*ifacts[n-bef])%mod;
		addon = (addon*ifacts[bef])%mod;
		addon = addon*(nums[i])%mod;
		ans = (ans + addon)%mod;

	}
	cout << ans << endl;
	cin >> ans;
}