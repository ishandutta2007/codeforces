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
 
const ll MAXN = 5e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll SQRT = 710;

int A[MAXN], ans_op[SQRT][SQRT], q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> q;
	while (q--) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			int x, y;
			cin >> x >> y;
			A[x] += y;
			for (int i = 1; i < SQRT; i++) ans_op[i][x % i] += y;
		} else {
			int x, y;
			cin >> x >> y;
			if (x < SQRT) cout << ans_op[x][y] << endl;
			else {
				ll ans = 0;
				for (int i = y; i < MAXN; i += x) ans += A[i];
				cout << ans << endl;
			}
		}
	}
	return 0;
}