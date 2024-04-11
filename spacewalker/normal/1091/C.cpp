#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <utility>
#include <cmath>

using namespace std;
typedef long long ll;

int main() {
	ll n; scanf("%lld", &n);
	vector<int> divs;
	for (int i = 1; i < 50000; ++i) {
		if (n % i == 0) divs.push_back(i);
	}
	vector<ll> compdivs(divs.begin(), divs.end());
	for (ll d : divs) {
		compdivs.push_back(n / d);
	}
	set<ll> ans;
	for (ll d : compdivs) {
		ans.insert((n/d) * (n-d) / 2 + (n/d));
	}
	for (ll x : ans) printf("%lld ", x);
	printf("\n");
	return 0;
}