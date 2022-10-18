#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	cin.tie(0);
	int N;
	cin >> N;

	vector<pii> prev;

	int cost = 0;
	const int inf = 1 << 29;

	rep(i,0,N) {
		int time;
		cin >> time;
		int ncost = cost + 20;

		auto it = lower_bound(all(prev), pii(time - 90, inf));
		if (it != prev.begin()) {
			--it;
			ncost = min(ncost, it->second +	50);
		}
		else ncost = min(ncost, 50);

		it = lower_bound(all(prev), pii(time - 1440, inf));
		if (it != prev.begin()) {
			--it;
			ncost = min(ncost, it->second +	120);
		}
		else ncost = min(ncost, 120);

		prev.emplace_back(time, ncost);
		cout << (ncost - cost) << '\n';
		cost = ncost;
	}

	exit(0);
}