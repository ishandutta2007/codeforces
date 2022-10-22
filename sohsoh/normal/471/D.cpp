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
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, A[MAXN], At[MAXN], B[MAXN], Bt[MAXN], lsp[MAXN];

ll KMP() {
	ll i = 0, j = 0, ans = 0;
	while (i < n) {
		if (B[j] == A[i]) i++, j++;
		if (j == m) ans++, j = lsp[j - 1];
		else if (i < n && B[j] != A[i]) {
			if (j != 0) j = lsp[j - 1];
			else i++;
		}
	}

	return ans;
}

int main() {
	fast_io;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> At[i];
	for (int i = 0; i < m; i++) cin >> Bt[i];
	if (m == 1) return cout << n << endl, 0;
	if (m > n) return cout << 0 << endl, 0;
	for (int i = 0; i < n - 1; i++) A[i] = At[i + 1] - At[i];
	for (int i = 0; i < m - 1; i++) B[i] = Bt[i + 1] - Bt[i];
	n--;
	m--;

	ll len = 0;
	lsp[0] = 0;
	ll i = 1;
	while (i < m) {
		if (B[i] == B[len]) len++, lsp[i] = len, i++;
		else {
			if (len != 0) len = lsp[len - 1];
			else lsp[i] = 0, i++;
		}
	}

	cout << KMP() << endl;
	return 0;
}