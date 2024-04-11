#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>
#include <string>
#include <array>
#include <set>
#include <map>
#include <cassert>
#include <deque>
#include <iomanip>


using namespace std;


#define ll long long
#define flt double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define emb emplace_back
#define prc cout << fixed << setprecision(10)



mt19937_64 rnd(123123);
const ll inf = 1e18;


int n;
vector<ll> a;


int32_t main() {
	if (1) {
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	}
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		a.resize(n);
		for (int i = 0; i < n; i += 1) {
			cin >> a[i];
		}
		/*
		vector<ll> p(n + 1);
		p[0] = 0;
		for (int i = 0; i < n; i += 1) {
			p[i + 1] = (p[i] ^ a[i]);
		}
		int rs = n;
		vector<ll> dp(n + 1);
		dp[0] = 0;
		for (int i = 1; i <= n; i += 1) {
			dp[i] = dp[i - 1];
			for (int j = 0; j < i; j += 1) {
				if (p[i] == p[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		*/
		int mx = 0;
		map<ll, int> dp;
		ll xr = 0;
		dp[0] = 0;
		for (int i = 0; i < n; i += 1) {
			xr ^= a[i];
			auto it = dp.find(xr);
			if (it != dp.end()) {
				mx = max(mx, it->second + 1);
			}
			dp[xr] = mx;
		}
		int rs = n;
		rs -= mx;
		cout << rs << "\n";
	}
	return 0;
}