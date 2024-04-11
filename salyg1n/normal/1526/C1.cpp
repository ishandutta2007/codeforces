#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <deque>
#include <unordered_map>
#include <time.h>
#include <set>
#include <cmath>
#include <queue>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main() {
	ll n;
	cin >> n;
	multiset<ll> q;
	ll now = 0, ans = 0;
	for (ll i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		if (x >= 0) {
			now += x;
			ans++;
		}
		else {
			if (now + x >= 0) {
				now += x;
				ans++;
				q.insert(x);
			}
			else if (q.size() && x > *q.begin()) {
				now -= *q.begin();
				now += x;
				q.extract(*q.begin());
				q.insert(x);
			}
		}
	}
	cout << ans;
	return 0;
}