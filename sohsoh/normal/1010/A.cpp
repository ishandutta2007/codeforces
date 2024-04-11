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
const ld EPS = 1e-9;

ll A[MAXN], B[MAXN], n, m;

bool solve(ld f) {
	ld w = f + m;
	ld x = w / ld(A[0]);
	w -= x;
	f -= x;
	for (int i = 1; i < n; i++) {
		x = w / ld(B[i]);
		f -= x;
		w -= x;
		x = w / ld(A[i]);
		f -= x;
		w -= x;
	}

	x = w / ld(B[0]);
	w -= x;
	f -= x;
	if (f >= 0) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < n; i++) cin >> B[i];	

	ld L = 0, R = 1e10;
	while (L + EPS < R) {
		ld mid = (R + L) / ld(2);
		bool ok = solve(mid);
		if (ok) R = mid;
		else L = mid;
	} 	
	
	if (L > 2e9) return cout << -1 << endl, 0; 

	cout << std::fixed << std::setprecision(10) << L << endl;
	return 0;
}