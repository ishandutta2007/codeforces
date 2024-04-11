#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll hc, dc, hm, dm, k, w, a;
		cin >> hc >> dc >> hm >> dm >> k >> w >> a;
		
		bool flag = false;
		hc += k * a;
		for (ll i = 0; i <= k; i++) {
			if ((hc + dm - 1) / dm >= (hm + dc - 1) / dc)
				flag = true;
		
			hc -= a;
			dc += w;
		}

		cout << (flag ? "YES" : "NO") << endl;
	}
	return 0;
}