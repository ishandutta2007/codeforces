#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int NMAX = 1000000; 

bool isPrime[NMAX];
vector<int> pList;

void initSieve() {
	for (int i = 2; i < NMAX; ++i) isPrime[i] = true;
	for (int i = 2; i < NMAX; ++i) {
		if (isPrime[i]) {
			for (int toMark = 2*i; toMark < NMAX; toMark += i) isPrime[i] = false;
			pList.push_back(i);
		}
	}
}

void addToFMap(ll n, map<ll, int> &f) {
	for (int p : pList) {
		while (n % p == 0) {
			++f[p];
			// printf("adding factor %lld\n", n);
			n /= p;
		}
	}
	if (n > 1) ++f[n];
}

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a%b));
}

vector<ll> divList;

void listFactors(ll seed, int listPlace, vector<pair<ll, int>> &ls) {
	// printf("run %lld pl %d\n", seed, listPlace);
	if (listPlace == ls.size()) divList.push_back(seed);
	else {
		ll cadd = 1;
		for (int k = 0; k <= ls[listPlace].second; ++k) {
			listFactors(seed * cadd, listPlace + 1, ls);
			cadd *= ls[listPlace].first;
		}
	}
}

int main() {
	initSieve();
	map<ll, int> factors;
	ll l, r, x, y; scanf("%lld %lld %lld %lld", &l, &r, &x, &y);
	addToFMap(x, factors); addToFMap(y, factors);
	vector<pair<ll, int>> facOrder(factors.begin(), factors.end());
	listFactors(1, 0, facOrder);
	int ans = 0;
	for (ll a : divList) {
		// printf("DIV %lld %lld\n", a, x*y/a);
		ll b = x*y/a;
		if (gcd(a, b) == x && l <= a && a <= r && l <= b && b <= r) {
			// printf("%lld %lld satisfy %d\n", a, b, (int)(l <= a <= r));
			++ans;
		} 
	}
	printf("%d\n", ans);
	return 0;
}