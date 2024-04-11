#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 11;
const int M = 42;
using ll = long long;

ll a[N];
int cnt[M];

ll gcd(ll a, ll b) {
	while(b != 0) {
		ll r = b;
		b = a % b;
		a = r;
	}
	return a;
}

int main() {
	srand(252);
	int n; cin >> n;
	for(int i = 0; i < n; i ++)
		scanf("%I64d", a + i);
	random_shuffle(a, a + n);

	ll ans = 1;
	for(int _ = 0; _ < min(n, 11); _ ++) {
		ll s = a[_];
		unordered_map <ll, int> mp;
		/*
		for(ll p = 1; p * p <= s; p ++)
			if(s % p == 0) {
				mp[p] = 0;
				mp[s / p] = 0;
			}
			*/
		for(int i = 0; i < n; i ++)
			mp[/*__gcd*/gcd(s, a[i])] ++;
		for(const auto &p : mp) {
			int cnt = 0;
			for(const auto &q : mp)
				if(q.first % p.first == 0)
					cnt += q.second;
			if(cnt * 2 >= n)
				ans = max(ans, p.first);
		}
	}

	cout << ans << '\n';
	return 0;
}