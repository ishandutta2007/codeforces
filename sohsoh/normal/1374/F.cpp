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
 
const ll MAXN = 1e4 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN], n, fen[MAXN];
vector<ll> ans_v;

void add(ll ind, ll val) {
	for (++ind; ind < MAXN; ind += ind & -ind) fen[ind] += val;
}

void range_update(ll l, ll r, ll val) {
	add(l, val);
	add(r + 1, -val);
}

ll point(ll ind) {
	ll ans = 0;
	for (++ind; ind > 0; ind -= ind & -ind) ans += fen[ind];
	return ans;
}

ll inv_cnt() {
	ll ans = 0;
	for (int i = 0; i < n; i++) ans += point(A[i]), range_update(0, A[i] - 1, 1);
	return ans;
}

void compress() {
	vector<pll> v;
	for (int i = 0; i < n; i++) v.push_back({A[i], i});
	sort(all(v));
	ll ind = 1;
	for (pll e : v) A[e.Y] = ind, ind++;	
}

void cycle(ll i) {
	ll x1 = A[i], x2 = A[i + 1], x3 = A[i + 2];
	A[i] = x3;
	A[i + 1] = x1;
	A[i + 2] = x2;
}

void move_to(ll i, ll j) {
	if (j == i + 1) {
		ans_v.push_back(i), ans_v.push_back(i), cycle(i), cycle(i);
		return;
	}

	if (j <= i) return;
	ans_v.push_back(j - 2);
	cycle(j - 2);
	move_to(i, j - 2);
}

ll solve() {
	cin >> n;
	fill(fen, fen + 4 * n, 0);
	ans_v.clear();
	for (int i = 0; i < n; i++) cin >> A[i];
	pll eq = {-1, -1};
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) if (A[i] == A[j]) eq = {i, j};
	compress();
	ll inv = inv_cnt();
	if (inv & 1 && eq.X == -1) return cout << -1 << endl, 0;
	if (inv & 1) swap(A[eq.X], A[eq.Y]);

	for (int i = 1; i <= n - 3; i++) {
		for (int j = 0; j < n; j++) { 
			if (A[j] == i) {
				move_to(i - 1, j);
				break;
			}
		}
	}

	ll q = 0;
	while (q < 10 && !is_sorted(A, A + n)) {
		ans_v.push_back(n - 3);
		cycle(n - 3);
		q++;
	} 

	if (!is_sorted(A, A + n)) return cout << -1 << endl, 0;
	cout << ans_v.size() << endl;
	for (ll e : ans_v) cout << e + 1 << sep;
	cout << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}