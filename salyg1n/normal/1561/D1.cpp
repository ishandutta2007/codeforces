#include <iostream>
#include <iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include <deque>
#include <string>
#include <cmath>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
//#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#pragma GCC optimize("O3")

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define print(a) for (auto& i : a) cout << i << " ";
#define input(a) for (auto& i : a) cin >> i;

//#define _GLIBCXX_DEBUG
//#define DEBUG

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	
	ll n, M;
	cin >> n >> M;
	
	vector<ll> a(n + 1, 0);
	for (ll i = 2; i <= n; ++i) {
		if (a[i])
			continue;
		for (ll j = i * i; j <= n; j += i)
			if (!a[j])
				a[j] = i;
	}
	vector<ll> dp(n + 1);
	dp[1] = 1;
	ll sum = 1;
	ll last = 0;
	for (ll i = 2; i <= n; ++i) {
		dp[i] = sum;
		ll now = i;
		vector<ll> b;
		while (a[now]) {
			b.push_back(a[now]);
			now /= a[now];
		}
		b.push_back(now);
		vector<ll> c;
		for (ll mask = 1; mask < (1 << (b.size())); ++mask) {
			ll now = mask;
			ll res = 1;
			while (now) {
				res *= b[__builtin_ctz(now)];
				now = (now & (now - 1));
			}
			c.push_back(res);
		}
		sort(all(c));
		c.erase(unique(all(c)), c.end());
		for (auto j : c) {
			last -= dp[(i / j) - 1];
			last += dp[i / j];
			last = ((last % M) + M) % M;
		}
		dp[i] += last;
		dp[i] = ((dp[i] % M) + M) % M;
		sum += dp[i];
		sum = ((sum % M) + M) % M;
	}
	cout << dp[n];
	return 0;
}