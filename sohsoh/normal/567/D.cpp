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
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, k, a, A[MAXN], m;

bool check(int x) {
	vector<int> v;
	v.push_back(0);
	v.push_back(n + 1);
	for (int i = 0; i < x; i++) v.push_back(A[i]);
	sort(all(v));	
	int ans = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		int tans = 0;
		int dist = v[i + 1] - v[i] - 1;
		if (dist >= a) tans = 1, dist -= a;
		tans += dist / (a + 1);
		ans += tans;
	} 
	return ans >= k;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k >> a >> m;
	for (int i = 0; i < m; i++) cin >> A[i];
	if (check(m)) return cout << -1 << endl, 0;
	int L = 1, R = m;
	while (L < R) {
		int mid = (L + R) / 2;
		if (check(mid)) L = mid + 1;
		else R = mid;
	}

	cout << L << endl;
	return 0;
}