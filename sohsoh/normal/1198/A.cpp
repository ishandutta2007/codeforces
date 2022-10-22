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

ll A[MAXN] = {0}, cnt[MAXN] = {0}, ps[MAXN] = {0};

int main() {
	fast_io;
	ll n, sz;
	cin >> n >> sz;
	for (int i = 0; i < n; i++) cin >> A[i];
	sz *= 8;
	sz /= n;
	if (sz > 21) sz = n;
	else sz = min(n, poww(2, sz, INF));
	
	sort(A, A + n);
	ll ind = 0, prv = -1;
	for (int i = 0; i < n; i++) {
		if (A[i] != prv) ind++, prv = A[i];
		A[i] = ind; 
		cnt[A[i]]++;
	}


	for (int i = 1; i < MAXN; i++) ps[i] = ps[i - 1] + cnt[i];	
	ll ans = INF;
	for (int i = 1; i <= n; i++) {
		ans = min(ans, ps[i - 1] + ps[n + 2] - ps[i + sz - 1]);
	}

	cout << ans << endl;

	return 0;
}