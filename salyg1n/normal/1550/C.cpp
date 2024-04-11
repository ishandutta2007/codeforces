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

ll d(ll x1, ll y1, ll x2, ll y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

bool check(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	return d(x1, y1, x2, y2) + d(x2, y2, x3, y3) == d(x1, y1, x3, y3);
}

int main() {
	ll t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		input(a);
		ll ans = 0;
		FOR(i, 0, n - 3) {
			if (!check(0, a[i], 1, a[i + 1], 2, a[i + 2]))
				ans++;
		}
		FOR(i, 0, n - 4) {
			if (!check(0, a[i], 1, a[i + 1], 2, a[i + 2]) && !check(0, a[i], 1, a[i + 1], 3, a[i + 3]) && !check(1, a[i + 1], 2, a[i + 2], 3, a[i + 3]) && !check(0, a[i], 2, a[i + 2], 3, a[i + 3]))
				ans++;
		}
		cout << ans + n + n - 1 << "\n";
	}
	return 0;
}