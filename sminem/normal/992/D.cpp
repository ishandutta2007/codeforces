#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[200005];
int r[200005];

typedef long long ll;

const ll INF = 3123123123123123123ll;

ll sm(ll x, ll y) {
	if (x * 1.0 * y > INF * 0.99)
		return INF;
	return x * y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	r[n+1] = -1;
	for (int i=n; i>=1; i--) {
		if (a[i] > 1)
			r[i] = i;
		else
			r[i] = r[i+1];
	}

	ll c = 0;

	for (int i=1; i<=n; i++) {
		int j = i;
		ll p = a[i], s = a[i];
		if (p == k*s)
			c++;

		while (1) {
			// vidi gde je sledeca
			int z = r[j+1];
			if (z == -1)
				z = n+1;
			if (z != j+1) {
				// kecevi? ima 
				int kec = z - j - 1;
				if (p != INF && p % k == 0 && 1 <= p/k-s && p/k-s <= kec) {
					c++;
				}
			}
			if (z == n+1)
				break;
			p = sm(p, a[z]);
			s += a[z] + z - j - 1;
			if (p == k*s)
				c++;
			if (p == INF)
				break;
			j = z;
		}
	}

	cout << c << '\n';


}