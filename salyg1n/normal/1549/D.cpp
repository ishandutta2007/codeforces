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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define range(i, n) for(ll i = 0; i < n; ++i)
#define FOR(i, a, b) for (ll i = a; i <= b; i++)
#define print(a) for (auto& i : a) cout << i << " ";
#define input(a) for (auto& i : a) cin >> i;

//#define _GLIBCXX_DEBUG
//#define DEBUG

using namespace std;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

const ll INF = 2e9;
ll n;
ll t[(ll)5e5 * 4];


void build(vector<ll>& a, ll v, ll l1, ll r1) {
	if (r1 - l1 <= 1)
		t[v] = a[l1];
	else {
		ll m = (l1 + r1) / 2;
		build(a, v * 2, l1, m);
		build(a, v * 2 + 1, m, r1);
		t[v] = gcd(t[v * 2], t[v * 2 + 1]);
	}
}

ll get_gcd(ll v, ll l1, ll r1, ll l, ll r) {
	if (r <= l1 || l >= r1)
		return 0;
	if (l1 >= l && r1 <= r)
		return t[v];
	ll m = (r1 + l1) / 2;
	return gcd(
		get_gcd(v * 2, l1, m, l, r)
		,
		get_gcd(v * 2 + 1, m, r1, l, r)
	);
}

int main() {
	ll t;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<ll> b(n);
		input(b);
		if (n == 1) {
			cout << 1 << "\n";
			continue;
		}
		vector<ll> a;
		FOR(i, 1, n - 1) {
			a.push_back(abs(b[i] - b[i - 1]));
		}
		n--;
		build(a, 1, 0, n);
		ll l = 0, r = 0, ans = 0;
		if (a[0] != 1)
			ans = 1;
		while (r < n - 1) {
			if (get_gcd(1, 0, n, l, r + 2) != 1) {
				r++;
			}
			else {
				l++;
			}
			ans = max(ans, r - l + 1);
		}
		cout << ans + 1 << "\n";
	}
	return 0;
}