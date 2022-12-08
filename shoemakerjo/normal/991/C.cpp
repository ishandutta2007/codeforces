#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll n;

bool check(ll k) {
	ll cur = n;
	ll o1 = 0LL;
	ll o2 = 0LL;
	ll half = (n+1)/2LL;
	while (cur > 0) {
		if (o1 >= half) return true;
		if (o2 > half) return false;
		ll take = min(k, cur);
		o1 += take;
		cur -= take;
		take = cur/10LL;
		o2 += take;
		cur -= take;

	}
	return o1 >= half;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// ll n;
	cin >> n;
	ll lo = 1LL;
	ll hi = n;
	while (lo < hi) {
		ll mid = (lo+hi)/2;
		if (check(mid)) { //this value worked
			hi = mid;
		}
		else { //got too few candies
			lo = mid+1;
		}
	}
	cout << lo << endl;
	cin >> n;
	
}