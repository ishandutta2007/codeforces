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

int A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> vec[2];

		ll ans = 0;
		for (int i = 1; i <= n; i++) cin >> A[i];
		
		for (int i = 1; i <= n; i++) {
			ll x;
			cin >> x;
			ans += x;
			vec[A[i]].push_back(x);
		}

		sort(all(vec[0]));
		sort(all(vec[1]));
		if (vec[1].size() > vec[0].size()) swap(vec[0], vec[1]);

		if (vec[0].size() == vec[1].size()) cout << ans * 2 - min(vec[0][0], vec[1][0]) << endl;
		else {
			int ind = 0;
			while (!vec[ind ^ 1].empty()) {
				ans += vec[ind].back();
				vec[ind].pop_back();
				ind ^= 1;
			}

			cout << ans << endl;
		}
	}
	return 0;
}