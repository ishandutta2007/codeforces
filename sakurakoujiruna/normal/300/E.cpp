#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e7 + 11;
using ll = long long;

ll cnt[N];
ll suf[N];
int p[N];

int main() {
	iota(p, p + N, 0);
	for(int i = 2; i < N; i ++) if(p[i] == i)
		for(int j = i * 2; j < N; j += i) p[j] = i;
	//ios :: sync_with_stdio(false);
	int n; cin >> n;
	while(n --) {
		int x; //cin >> x;
		scanf("%d", &x);
		suf[x] ++;
	}
	for(int i = N - 1; i >= 0; i --)
		suf[i] += suf[i + 1];
	for(int i = N - 1; i >= 2; i --) {
		cnt[p[i]] += suf[i];
		suf[i / p[i]] += suf[i];
	}

	auto check = [&](ll n) {
		for(int i = 2; i < N; i ++) if(p[i] == i) {
			ll tmp = 0;
			for(ll t = n / i; t > 0; t /= i)
				tmp += t;
			if(tmp < cnt[i])
				return false;
		}
		return true;
	};

	ll l = 1, r = (ll)1e13 + 11;
	while(l + 1 < r) {
		ll m = (l + r) / 2;
		if(check(m - 1))
			r = m;
		else
			l = m;
	}
	cout << l << '\n';
	return 0;
}