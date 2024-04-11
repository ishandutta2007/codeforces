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

ll n;
ll mx_prv[MAXN], mn_prv[MAXN], A[MAXN], dp[MAXN];
set<pll> st_mn, st_mx;

void upd(ll& a, ll b) {
	a = min(a, b);
}

void upd_mx(ll i) {
	if (mx_prv[i] >= 0) upd(dp[i], dp[mx_prv[i]] + 1);
	while (!st_mx.empty() && st_mx.begin() -> X <= A[i]) {
		upd(dp[i], dp[st_mx.begin() -> Y] + 1);
	       	st_mx.erase(st_mx.begin());	
	}
}

void upd_mn(ll i) {
	if (mn_prv[i] >= 0) upd(dp[i], dp[mn_prv[i]] + 1);
	while (!st_mn.empty() && st_mn.rbegin() -> X >= A[i]) {
		upd(dp[i], dp[st_mn.rbegin() -> Y] + 1);
	       	st_mn.erase(*st_mn.rbegin());	
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];

	stack<ll> st;
	for (int i = 0; i < n; i++) {
		while (!st.empty() && A[st.top()] < A[i]) st.pop();
		if (st.empty()) mx_prv[i] = -1;
		else mx_prv[i] = st.top();
		st.push(i);
	}
	
	while (!st.empty()) st.pop();
	
	for (int i = 0; i < n; i++) {
		while (!st.empty() && A[st.top()] > A[i]) st.pop();
		if (st.empty()) mn_prv[i] = -1;
		else mn_prv[i] = st.top();
		st.push(i);
	}

	dp[0] = 0;
	st_mn.insert({A[0], 0});
	st_mx.insert({A[0], 0});
	for (int i = 1; i < n; i++) {
		dp[i] = dp[i - 1] + 1;
		upd_mn(i);
		upd_mx(i);
		st_mx.insert({A[i], i});
		st_mn.insert({A[i], i});
	}

	cout << dp[n - 1] << endl;	
	return 0;
}