#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define maxn 1000010

const int mod = 998244353;
int n;
ll facts[maxn];

void add(ll&a, ll b) {
	a = (a+b)%mod;
}

ll mult(ll a, ll b) {
	return (a*b)%mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	ll ans = 0LL;

	ll fi = 1LL;
	ll se = 1LL;
	facts[0] = 1LL;
	for (int i = 1; i <= n; i++) {
		facts[i] = (facts[i-1] * i)%mod;
	}

	for (int i = 0; i < n; i++) {
		if (i == 0) add(ans, mult(fi, facts[n-i]));
		else {
			add(ans, mult(fi, (facts[n-i]+mod-1LL)%mod));
		}
		fi = mult(fi, n-i);
	}

	cout << ans << endl;
}