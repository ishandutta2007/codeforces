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

const ll MAXN = 1e6 + 10;
const ll INF = 1e15;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, A, c_f, c_m, m, B[MAXN], C[MAXN];
pll sort_back[MAXN];

inline ll calc(ll mn) {
	ll t_m = m;
	for (int i = 1; i <= n; i++) {
		C[i] = B[i];
		if (C[i] < mn) {
			t_m -= mn - C[i];
			C[i] = mn;
		}
	}

	if (t_m < 0) return -1 * mn;
	
	ll ans = mn * c_m; 
	for (int i = n; i >= 1; i--) {
		if (t_m >= A - C[i]) {
			t_m -= A - C[i];
			C[i] = A;
			ans += c_f;
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> A >> c_f >> c_m >> m;
	for (int i = 1; i <= n; i++) cin >> B[i], sort_back[i] = {B[i], i};
	sort(B + 1, B + n + 1);
	sort(sort_back + 1, sort_back + n + 1);

	ll L = 0, R = A;
	while (L < R - 1000) {
		ll mid1 = L + (R - L) / 3ll, mid2 = R - (R - L) / 3ll; 
		if (calc(mid1) >= calc(mid2)) R = mid2;
		else L = mid1;
	}

	ll ans_f = 0, ans_i = 0;
	while (L <= R) {
		if (calc(L) > ans_f) ans_f = calc(L), ans_i = L;
		L++;
	}

	calc(ans_i);
	for (int i = 1; i <= n; i++) B[sort_back[i].Y] = C[i];
	cout << ans_f << endl;
	for (int i = 1; i <= n; i++) cout << B[i] << sep;
       	cout << endl;	
	return 0;
}