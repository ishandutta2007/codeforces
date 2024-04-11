/*
	
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9


ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
ll A[MAXN];

int main() {
	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
	ll negl = 0, posl = 0, negr = 0, posr = 0, z = 0;
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		if (A[i] == 0) z++;		
		else if (A[i] < 0) negr++;
		else if (A[i] > 0) posr++;	
	}

	ll ans = INF;
	for (int i = 0; i < n - 1; i++) {
		if (A[i] > 0) posr--, posl++;
		else if (A[i] < 0) negr--, negl++;
		ans = min(ans, posl + negr);
	}

	ans += z;
	cout << ans << endl;
}