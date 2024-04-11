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
#define int			    ll

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 4e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int A[MAXN], B[MAXN], p1 = 0, p2 = 0, n, m, sz;
pair<int, pair<int, int>> diff1[MAXN], diff2[MAXN];

void as_hard_as_fft(vector<pair<int, int>> v) {
	if (v.empty()) {
		cout << 0 << endl;
		return;
	}
	
	if (v.size() == 1) {
		cout << 1 << endl;
		cout << v[0].X << sep << v[0].Y << endl;
		return;
	}

	if (v[0] == v[1]) {
		cout << 0 << endl;
		return;
	}

	if (v[0].X == v[1].X) {
		cout << 1 << endl;
		cout << v[0].X << sep << v[1].Y << endl;
		return;
	} 

	if (v[0].Y == v[1].Y) {
		cout << 1 << endl << v[1].X << sep << v[1].Y << endl;
		return;
	}

	cout << 2 << endl << v[0].X << sep << v[0].Y << endl << v[1].X << sep << v[1].Y << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> B[i];
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) diff1[sz] = {-2 * (A[i] - B[j]), {i + 1, j + 1}}, diff2[sz] = {-2 * (A[i] - B[j]), {i + 1, j + 1}}, sz++;
	
	sz++;
	sort(diff1, diff1 + sz);
	reverse(diff1, diff1 + sz);
	sort(diff2, diff2 + sz);
	ll diff = 0;
	for (int i = 0; i < n; i++) diff += A[i];
	for (int j = 0; j < m; j++) diff -= B[j];
	ll ans = INF;

	/*
	debug(diff)
	for (int i = 0; i < sz; i++) cerr << diff1[i].X << sep;
	cerr << endl;
	for (int i = 0; i < sz; i++) cerr << diff2[i].X << sep;
	cerr << endl;*/ 

	pll p = {0, 0};
	while (p1 < sz) {
		while (p2 + 1 < sz && abs(diff + diff1[p1].X + diff2[p2].X) >= abs(diff + diff1[p1].X + diff2[p2 + 1].X)) p2++;


		if (diff1[p1].Y.X == diff2[p2].Y.X || diff1[p1].Y.Y == diff2[p2].Y.Y) {
			p1++;
			continue;
		}
		
		if (abs(diff + diff1[p1].X + diff2[p2].X) < ans) {
			ans = abs(diff + diff1[p1].X + diff2[p2].X);
			p = {p1, p2};		
		}
		p1++;
	}
	
	if (abs(diff) < ans) {
		cout << abs(diff) << endl;
		cout << 0 << endl;
		return 0;
	}

	cout << ans << endl;
	vector<pair<int, int>> v;
	if (diff1[p.X].Y.X) v.push_back(diff1[p.X].Y);
	if (diff2[p.Y].Y.X) v.push_back(diff2[p.Y].Y);
	as_hard_as_fft(v);
	return 0;
}