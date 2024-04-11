#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll n, k;
ll a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k >> a >> b;

	ll mingc = n*k;
	ll maxgc = 1;
	ll cur;

	for (ll i = 0LL; i <= n; i+=1LL) {

		ll o1 = i * k - b - a;
		ll o2 = i * k - b + a;
		ll o3 = i * k + b - a;
		ll o4 = i * k + b + a;

		if (o1 > 0 && o1 <= n*k) {
			cur = __gcd(n*k, o1);
			mingc = min(mingc, cur);
			maxgc = max(maxgc, cur);
		}
		if (o2 > 0 && o2 <= n*k) {
			cur = __gcd(n*k, o2);
			mingc = min(mingc, cur);
			maxgc = max(maxgc, cur);
		}
		if (o3 > 0 && o3 <= n*k) {
			cur = __gcd(n*k, o3);
			mingc = min(mingc, cur);
			maxgc = max(maxgc, cur);
		}
		if (o4 > 0 && o4 <= n*k) {
			cur = __gcd(n*k, o4);
			mingc = min(mingc, cur);
			maxgc = max(maxgc, cur);
		}
	}


	cout << n*k / maxgc << " " << n*k / mingc << endl;

}