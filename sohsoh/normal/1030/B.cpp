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

int d, n;
pll convert(int x, int y) {
	int tx = y - x, ty = x + y;
	return {tx, ty};
} 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> d;
	int m;
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		if (x - y + d >= 0 && x - y - d <= 0 && x + y >= d && x + y <= 2 * n - d) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}