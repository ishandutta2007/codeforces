/*
    Soheil Mohammadkhani
    Sos Goge Tabarok :)
*/
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
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN], K[MAXN], seg[MAXN] = {0}, lz[MAXN] = {0}, D[MAXN], n, k_s[MAXN] = {0}, p = 0;

void fen_add(ll ind, ll diff) {
	ind++;
	while (ind <= n) k_s[ind] += diff, ind += ind & (-ind);
}

ll fen_sum(ll ind) {
	ind++;
	ll ans = 0;
	while (ind > 0) ans += k_s[ind], ind -= ind & (-ind);
	return ans;
}

void push(ll v, ll seg_s, ll seg_e) {
	if (lz[v] != 0) {
		seg[v] += (seg_e - seg_s + 1) * lz[v];
		if (seg_s < seg_e) {
			lz[2 * v + 2] += lz[v];
			lz[2 * v + 1] += lz[v];
		}
		lz[v] = 0;
	}
}

void update(ll v, ll ss, ll se, ll us, ll ue, ll val) {
	push(v, ss, se);
	if (ss > se || ss > ue || se < us) return; 
        if (ss >= us && se <= ue) { 
		seg[v] += (se - ss + 1) * val; 
		if (ss != se) { 
			lz[v * 2 + 1] += val; 
			lz[v * 2 + 2] += val; 
		} 
		
		return;
	}

	ll mid = (ss + se) / 2;
	update(2 * v + 1, ss, mid, us, ue, val);
	update(2 * v + 2, mid + 1, se, us, ue, val);
	seg[v] = seg[2 * v + 1] + seg[2 * v + 2];
	return; 
}

ll sum(ll v, ll ss, ll se, ll qs, ll qe) {
	push(v, ss, se);
	if (ss > se || ss > qe || se < qs) return 0;
	if (ss >= qs && se <= qe) return seg[v];
	
	ll mid = (ss + se) / 2;
	return sum(2 * v + 1, ss, mid, qs, qe) + sum(2 * v + 2, mid + 1, se, qs, qe);
}

set<pll> st;

int main() {
	//fast_io;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	ll ps = 0;
	for (int i = 0; i < n - 1; i++) cin >> K[i], ps += K[i], A[i + 1] -= ps, fen_add(i + 1, ps);	
	for (int i = 0; i < n; i++) update(0, 0, n - 1, i, i, A[i]);	

	for (int i = 0; i < n - 1; i++) {
		ll x = A[i + 1] - A[i];
		if (x > 0) st.insert({i, x});
	}
	
	st.insert({n - 1, INF});

	ll q;
	cin >> q;
	while (q--) {
		char c;
		cin >> c;
		if (c == 's') {
			ll l, r;
			cin >> l >> r;
			l--;
			r--;
			ll ans = sum(0, 0, n - 1, l, r) + fen_sum(r);
			if (l > 0) ans -= fen_sum(l - 1);
			cout << ans << endl;
		} else {
			ll ind, x;
			cin >> ind >> x;
			ind--;
			while (x > 0) {
				auto it = st.lower_bound({ind, 0});
				ll ind2 = it -> X, val = it -> Y;
				st.erase(it);
				ll red = min(x, val);
				x -= red;
				val -= red;
				if (val > 0) st.insert({ind2, val});
				update(0, 0, n - 1, ind, ind2, red);	
			}
			
			if (ind > 0) {
				ll x = sum(0, 0, n - 1, ind, ind) - sum(0, 0, n - 1, ind - 1, ind - 1);
				if (x > 0) { 
					auto it = st.lower_bound({ind - 1, 0});
					if (it -> X == ind - 1) st.erase(it); 
					st.insert({ind - 1, x});
				}
			}
		}
	}
	return 0;
}