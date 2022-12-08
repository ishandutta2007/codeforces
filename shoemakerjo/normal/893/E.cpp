#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define maxn 2000010

ll mod;
ll facts[maxn];
ll invfacts[maxn];
ll twos[maxn];

bool isprime(int u) {
	for (int i = 2; i <= sqrt(u); i++) {
		if (u%i == 0) return false;
	}
	return true;
}

ll inv(ll base, ll pow) {
	if (pow == 0LL) return 1LL;
	if (pow == 1LL) return base;
	if (pow % 2LL == 1LL) {
		ll tempo = inv(base, pow-1LL);
		ll ans = (tempo*base)%mod;
		return ans;
	}
	ll tempo = inv(base, pow/2LL);
	ll ans = (tempo*tempo)%mod;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	int x, y;
	mod = 1000000007LL;

	vector<int> primes;
	for (int i = 2; i <= 1010; i++) {
		if (isprime(i)) {
			primes.push_back(i);
		}
	}
	facts[0] = 1LL;
	invfacts[0] = 1LL;
	twos[0] = 1LL;
	for (int i = 1; i < maxn; i++) {
		facts[i] = (facts[i-1]*(i+0LL))%mod;
		invfacts[i] = inv(facts[i], mod-2LL);
		twos[i] = (twos[i-1]*2LL)%mod;
	}


	for (int Q = 0; Q < q; Q++) {
		cin >> x >> y;
		vector<int> nums;
		for (int i = 0; i < primes.size(); i++) {
			int cur = 0;
			while (x % primes[i] == 0) {
				cur++;
				x = x/primes[i];
			}	
			if (cur > 0) nums.push_back(cur);
		}
		if (x > 1) nums.push_back(1);
		ll ans = 1LL;
		for (int i = 0; i < nums.size(); i++) {
			int cur = nums[i];
			ans = (ans*facts[cur+y-1])%mod;
			ans = (ans*invfacts[y-1])%mod;
			ans = (ans*invfacts[cur])%mod;
		}
		ans = (ans*twos[y-1])%mod;
		cout << ans << '\n';
	}
	// cout << pr2imes.size() << endl;
	cin >> q;
}