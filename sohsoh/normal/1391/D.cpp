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
 
const ll MAXN = 1e6 + 10; // change
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[3][MAXN], S[2][2][MAXN] = {0};

int main() {
 	fast_io;
	ll n, m;
	cin >> n >> m;
	if (n > 3 && m > 3) return cout << -1 << endl, 0;
	if (n == 1 || m == 1) return cout << 0 << endl, 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == '1') A[i][j] = 1;
			else A[i][j] = 0;
		}
	}

	if (n == 2) {
		ll ans = 0;
		for (int i = 0; i < m; i++) {
			ll x = A[0][i] + A[1][i];
			if (i % 2 == x % 2) ans++;
		}

		ll ans2 = 0;
		for (int i = 0; i < m; i++) {
			ll x = A[0][i] + A[1][i];
			if (x % 2 != i % 2) ans2++;
		}

		return cout << min(ans, ans2) << endl, 0;
	}

	for (int i = 0; i < m; i++) {
		ll x = A[0][i] + A[1][i];
		if (x % 2 != i % 2) S[0][0][i]++;
	       	else S[0][1][i]++;
		x = A[1][i] + A[2][i];
		if (x % 2 != i % 2) S[1][0][i]++;
		else S[1][1][i]++;	
	}

	ll ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
	for (int i = 0; i < m; i++) {
		ans1 += max(S[0][0][i], S[1][0][i]);
		ans2 += max(S[0][1][i], S[1][1][i]);
		ans3 += max(S[0][0][i], S[1][1][i]);
		ans4 += max(S[0][1][i], S[1][0][i]);
	}

	cout << min(min(ans1, ans2), min(ans3, ans4)) << endl;
	return 0;
}