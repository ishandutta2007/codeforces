#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 5;
ll pf[MAXN];

ll f(vector<ll> &v) {
	//for(auto x : v)
	//	cout << x << " ";
	//cout << endl;
	pf[0] = v[0];
	for(int i = 1; i < v.size(); i++)
		pf[i] = pf[i - 1] + v[i];
	ll sum = accumulate(v.begin(), v.end(), 0);
	ll tmp = 0;
	for(int i = 1; i < v.size(); i++)
		tmp += v[i] * i;
	ll be = tmp;
	for(int i = 1; i < v.size(); i++) {
		tmp += pf[i - 1];
		tmp -= (sum - pf[i - 1]);
		be = min(be, tmp);
	}
	return be;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<ll> v(n);
	ll sum = 0;
	for(auto &x : v) {
		cin >> x;
		sum += x;
	}
	if(sum == 1) {
		cout << "-1\n";
		return 0;
	}
	ll ans = LLONG_MAX;
	vector<ll> pf;
	for(ll p = 2; p * p <= sum; p++) {
		if(sum % p)
			continue;
		pf.push_back(p);
		while(sum % p == 0)
			sum /= p;
	}
	if(sum > 1)
		pf.push_back(sum);
	for(auto p : pf) {
		auto pv = v;
		for(auto &x : pv)
			x %= p;
		ll cur = 0, tans = 0;
		int po;
		vector<ll> t;
		tans = 0;
		po = 0;
		while(po < pv.size()) {
			ll x = pv[po];
			if(cur + x < p) {
				cur += x;
				t.push_back(x);
				po++;
			}
			else {
				ll y = p - cur;
				t.push_back(y);
				pv[po] -= y;
				tans += f(t);
				t.clear();
				cur = 0;
			}
		}
		ans = min(ans, tans);
	}
	cout << ans << '\n';
}