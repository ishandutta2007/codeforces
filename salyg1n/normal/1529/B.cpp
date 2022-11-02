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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		vector<ll> a(n);
		for (auto& i : a)
			cin >> i;
		sort(a.begin(), a.end());
		ll cnt = 0;
		ll mn = 1e18;
		ll last = -1e18;
		for (auto i : a) {
			if (i > 0)
				break;
			if (i <= 0) {
				cnt++;
				mn = min(i - last, mn);
				last = i;
			}
		}
		ll flag = 0;
		for (auto i : a)
			if (i > 0 && i <= mn)
				flag = 1;
		cout << cnt + flag << "\n";
	}
	return 0;
}