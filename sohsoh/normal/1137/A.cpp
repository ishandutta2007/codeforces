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
 
const ll MAXN = 1e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN][MAXN], B[MAXN][MAXN], C[MAXN][MAXN], n, m, mx_row[MAXN], mx_col[MAXN];

void arr_compress(vector<ll>& v) {
	vector<pll> tv;
	for (int i = 0; i < v.size(); i++) tv.push_back({v[i], i});
	sort(all(tv));
	ll ind = 0, prv = -1;
	for (pll e : tv) {
		if (e.X != prv) prv = e.X, ind++;
		v[e.Y] = ind;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> A[i][j];
	for (int i = 0; i < n; i++) {
		vector<ll> v;
		for (int j = 0; j < m; j++) v.push_back(A[i][j]);
		arr_compress(v);
		for (int j = 0; j < m; j++) B[i][j] = v[j];
		mx_row[i] = *max_element(all(v));
	}

	for (int j = 0; j < m; j++) {
		vector<ll> v;
		for (int i = 0; i < n; i++) v.push_back(A[i][j]);
		arr_compress(v);
		for (int i = 0; i < n; i++) C[i][j] = v[i];
		mx_col[j] = *max_element(all(v));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ll t = max(B[i][j], C[i][j]);
			cout << max(mx_row[i] + t - B[i][j], mx_col[j] + t - C[i][j]) << sep;
		}

		cout << endl;
	}
	return 0;
}