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
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN], n, F[MAXN] = {0}, B[MAXN], ps[MAXN], cnt[MAXN] = {0}, cnt2[MAXN] = {0}, ps2[MAXN], lst[MAXN] = {0};
map<ll, vector<ll>> mp;

void compress_arr() {
	vector<pll> v;
	for (int i = 1; i <= n; i++) v.push_back({A[i], i});
	sort(all(v));
	ll ind = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0 || v[i].X > v[i - 1].X) ind++;
		A[v[i].Y] = ind;
	}
}

ll count_range(ll l, ll r, ll x) {
	auto it = mp.find(x);
	if (it == mp.end()) return 0;
	return upper_bound(all(it -> Y), r) - lower_bound(all(it -> Y), l);
}

ll solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	compress_arr();
	for (int i = 1; i <= n; i++) {
		if (F[A[i]] == 0) F[A[i]] = i;
		lst[A[i]] = i;
		mp[A[i]].push_back(i);
		cnt[A[i]]++;
	}

	ll mx = *max_element(A + 1, A + n + 1);
	B[1] = 1;
	ps[0] = ps2[0] = 0;
	ps[1] = 1;
	ps2[1] = cnt[1];
	for (int i = 2; i <= mx; i++) {
		ll f = F[i];
		if (count_range(1, f, i - 1) == count_range(1, n, i - 1)) B[i] = 1;
		else B[i] = 0;
		ps[i] = ps[i - 1] + B[i];
		ps2[i] = ps2[i - 1] + cnt[i];
	}

	ll ans = 0;
	for (int i = 1; i <= mx; i++) {
		ll pr = count_range(0, F[i], i - 1);
		ll L = i, R = mx;
		while (L < R) {
			ll mid = (L + R + 1) / 2;
			ll s = ps[mid] - ps[i];
			if (mid == i || s == mid - i) L = mid;
			else R = mid - 1;
		}
		
		ll tans = pr + ps2[L] - ps2[i - 1];
		tans += count_range(lst[L], n + 1, L + 1);
		ans = max(ans, tans);
	}

	mx = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, cnt2[A[i] - 1] + count_range(i, n, A[i]));
		cnt2[A[i]]++;
	}


	cout << n - ans << endl;
	
	mp.clear();
	fill(F, F + n + 10, 0);
	fill(A, A + n + 10, 0);
	fill(lst, lst + n + 10, 0);
	fill(ps, ps + n + 10, 0);
	fill(ps2, ps2 + n + 10, 0);
	fill(cnt, cnt + n + 10, 0);
	fill(cnt2, cnt2 + n + 10, 0);
	fill(B, B + n + 10, 0);
	
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}