/*
    Soheil Mohammadkhani
    OK, im back :)
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
 
const ll MAXN = 5e4 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<ll> ind[26];
ll n, A[MAXN];
pll dp[110][MAXN];

int main() {
	fast_io;
	string s;
	cin >> s;
	n = s.size();
	for (int i = 0; i < 110; i++) for (int j = 0; j < MAXN; j++) dp[i][j] = {10 * MAXN, 2};
	for (int i = 0; i < n; i++) {
		A[i] = s[i] - 'a';
		ind[A[i]].push_back(i);
	}

	for (int i = 0; i < 26; i++) ind[i].push_back(INF);
	
	for (int i = 0; i < n; i++) dp[1][i] = {i, 1};
	for (int i = n - 1; i >= 0; i--) {
		ll x = *upper_bound(all(ind[A[i]]), i);
	       	if (x <= dp[2][i + 1].X) dp[2][i] = {x, 1};
		else dp[2][i] = {dp[2][i + 1].X, 0};
	}
	
	for (int sz = 3; sz < 101; sz++) {
		for (int i = n - 1; i >= 0; i--) {
			ll lw = dp[sz - 2][i + 1].X;
	//		if (i == n - 1 && sz == 3) debug(lw)
			ll x = *upper_bound(all(ind[A[i]]), lw);	
			if (x <= dp[sz][i + 1].X) dp[sz][i] = {x, 1};
			else dp[sz][i] = {dp[sz][i + 1].X, 0};		
		}
	}
	
	ll ans_sz = 0, p = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j].X < MAXN) ans_sz = i, p = j;
		} 
	}

	string ans = "";
	ll sz = ans_sz;
	while (true) {
		string ans_rev = ans;
		reverse(all(ans_rev));
		if (sz == 0) return cout << ans + ans_rev << endl, 0;
		if (sz == 1) return cout << ans + char(A[p] + 'a') + ans_rev << endl, 0;	
		if (dp[sz][p].Y) {
			ans += char(A[p] + 'a');
			sz -= 2;
			p++;
		} else {
			p++;
		}
	}
		
	return 0;
}