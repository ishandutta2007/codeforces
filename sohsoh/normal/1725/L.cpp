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

ll n, ps[MAXN], fen[MAXN];
vector<ll> vec;

inline void update(int ind, int val) {
	for (++ind; ind < MAXN; ind += ind & -ind)
		fen[ind] += val;
}

inline int query(int ind) {
	int ans = 0;
	for (++ind; ind > 0; ind -= ind & -ind)
		ans += fen[ind];

	return ans;
}

inline int ind(ll x) {
	return lower_bound(all(vec), x) - vec.begin();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		ps[i] = ps[i - 1] + x;
		if (ps[i] < 0) return cout << -1 << endl, 0;
		
		vec.push_back(ps[i]);
	}

	sort(all(vec));
	vec.resize(unique(all(vec)) - vec.begin());
	for (int i = 1; i < n; i++) {
		ans += i - 1 - query(ind(ps[i]));
		update(ind(ps[i]), 1);
	
		if (ps[i] > ps[n]) return cout << -1 << endl, 0;
	}

	cout << ans << endl;
	return 0;
}