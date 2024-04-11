#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

using ll = long long;
using vi = vector<int>;

const int N = 1000005;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	ll n;
	while (cin >> n) {
		if (n == 1) {
			cout << 3 << endl;
			continue;
		}
		ll st = 0, en = 1000000000000ll, md;
		while(en - st > 1) {
			md = (st + en) / 2ll;
			ll cn = (md + 1) / 2ll - 1ll + md / 4ll - 1;
			if (cn > n) en = md;
			else st = md;			
		}
		ll cn = (st + 1) / 2 - 1 + st / 4ll - 1;
		if (cn == n) {
			if (st & 1 || st % 4 == 0) cout << st << endl;
			else cout << st - 1 << endl;
		}
		else {
			if (en & 1 || en % 4 == 0) cout << en << endl;
			else cout << en - 1 << endl;
		}
	}
	
	return 0;
}