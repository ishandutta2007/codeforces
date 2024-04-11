#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MSK = (1 << 30) - 1;
const int PI = 303;
vector<int> ps;
int prime[2001];
map<ll, ll> dp;

ll to(ll a, ll b, ll c, ll i) {
	return (a<<45)|(b<<30)|(c<<15)|i;
}

ll solve(int a, int b, int c, int i) {
	int p = ps[i];
	if(a < p && b < p && c < p)
		return 1;
	if(a < p)
		a = 1;
	if(b < p)
		b = 1;
	if(c < p)
		c = 1;
	if(a > b)
		swap(a, b);
	if(a > c)
		swap(a, c);
	if(b > c)
		swap(b, c);
	ll X = to(a, b, c, i);
	int y = dp[X];
	if(y != 0)
		return y;
	ll ans = 0;
	int qa = a, qb, qc, ea = 0, eb, ec;
	while(qa > 0) {
		qb = b, eb = 0;
		while(qb > 0) {
			qc = c, ec = 0;
			while(qc > 0) {
				ans += (ll)(ea + eb + ec + 1) * solve(qa, qb, qc, i + 1);
				ans &= MSK;
				qc /= p;
				ec++;
			}
			qb /= p;
			eb++;
		}
		qa /= p;
		ea++;
	}
	return dp[X] = ans;
}

void sieve() {
	for(int p = 2; p <= 2000; p++) {
		if(prime[p])
			continue;
		ps.push_back(p);
		for(int q = p; q <= 2000; q += p)
			prime[q] = p;
	}
}

int main() {
	sieve();
	ps.push_back(2500);
	int a, b, c;
	cin >> a >> b >> c;
	ll x = solve(a, b, c, 0);
	cout << x << '\n';
	//cout << dp.size() << endl;
}