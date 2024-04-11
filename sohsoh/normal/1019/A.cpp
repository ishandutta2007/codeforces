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
 
const ll MAXN = 3e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<ll> V[MAXN];
vector<pll> A;
ll n, m;

ll solve(ll x) {
	multiset<ll> st;
	ll ans = 0;
	ll vv = V[1].size();
	for (int i = 0; i < n; i++) st.insert(A[i].Y);
       	for (int i = 2; i <= m; i++) {
		for (int j = 0; j < ll(V[i].size()) - x; j++) {
			vv++;
		       	ans += V[i][j];
		       	st.erase(st.find(V[i][j])); 
		}
	}
	
	while (vv < x + 1) {
		if (st.empty()) return INF;
		ans += *st.begin();
		st.erase(st.begin());
		vv++;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		V[x].push_back(y);
		if (x != 1) A.push_back({x, y});
		else A.push_back({1, INF});	
	}

	for (int i = 0; i <= m; i++) sort(all(V[i]));
	
	ll ans = INF;
	for (int i = 0; i <= n; i++) ans = min(ans, solve(i));
	cout << ans << endl;
	return 0;
}