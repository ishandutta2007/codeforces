#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

const ll mod = 1000000007;

int main() {
	cin.sync_with_stdio(false);
	ll L;
	int N, K;
	cin >> N >> L >> K;
	vi vec(N);
	rep(i,0,N) cin >> vec[i];
	ll whole = L / N;
	int partial = (int)(L % N);
	map<int, ll> parts;
	parts[0] = 1;
	ll res = 0;
	rep(k,0,K) {
		map<int, ll> ncounts, nparts;
		ll a = 0, b = 0;
		rep(i,0,N) {
			auto it = parts.upper_bound(vec[i]);
			--it;
			a += it->second;
			if (i < partial)
				b += it->second;
			ncounts[vec[i]] += it->second;
		}
		a %= mod;
		b %= mod;
		ll part = 0;
		trav(pa, ncounts) {
			part += pa.second;
			part %= mod;
			nparts[pa.first] = part;
		}
		if (k <= whole)
			res += b;
		if (whole - k > 0)
			res += a * ((whole - k) % mod) % mod;
		res %= mod;
		parts.swap(nparts);
	}
	cout << res << endl;
}