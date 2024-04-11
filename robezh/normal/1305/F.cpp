#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50, M = (int)1e6 + 50;

int n;
ll num[N];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool p[M];
int pm[M], pms = 0;

ll solve(ll d) {
	ll res = 0;
	for(int i = 0; i < n; i++) {
		ll dif = (num[i] + d - 1) / d * d - num[i];
		if(num[i] / d >= 1) dif = min(dif, num[i] - num[i] / d * d);
		res += dif;
	}
	return res;
}

void add_prime(vector<ll> &ps, ll x) {
	for(int i = 0; i < pms; i++) {
		if(x % pm[i] == 0) {
			ps.push_back(pm[i]);
			while(x % pm[i] == 0) x /= pm[i];
		}
	}
	if(x > 1) ps.push_back(x);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(p, p + M, true);
	for(int i = 2; i < M; i++) {
		if(p[i]) {
			pm[pms++] = i;
			for(int j = i; j < M; j += i) p[j] = false;
		}
	}

	cin >> n;
	for(int i = 0; i < n; i++) cin >> num[i];

	ll res = N;
	for(int it = 0; it < 30; it++) {
		vector<ll> ps;
		ll x = num[rng() % n];
		add_prime(ps, x);
		if(x - 1 >= 1) add_prime(ps, x - 1);
		add_prime(ps, x + 1);
		for(auto d : ps) res = min(res, solve(d));
	}
	cout << res << endl;

}