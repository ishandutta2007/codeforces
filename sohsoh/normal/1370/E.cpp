#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n;
	string s, t;
	cin >> n >> s >> t;
	if (count(all(s), '1') != count(all(t), '1')) return cout << -1 << endl, 0;
	set<ll> st[2];
	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			if (s[i] == '1') st[0].insert(i);
			else st[1].insert(i);
		}
	}
	
	ll ans = 0;
	while (!st[0].empty() && !st[1].empty()) {
		ll ind = 0;
		if (*st[1].begin() < *st[0].begin()) ind = 1;
		ll lst = *st[ind].begin();
		st[ind].erase(st[ind].begin());
		while (true) {
			ind = 1 - ind;
			auto it = st[ind].lower_bound(lst);
			if (it == st[ind].end()) break;
			lst = *it;
			st[ind].erase(it);
		}

		ans++;
	}

	ans += st[0].size();
	ans += st[1].size();
	cout << ans << endl;
	return 0;
}