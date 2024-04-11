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
 
const ll MAXN = 5000 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

pair<bool, bool> B[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	ll n = s.size();
	for (int i = 0; i < n; i++) {
		bool b = true;
		ll cnt = 0;
		for (int j = i; j < n; j++) {
			if (s[j] == '(' || s[j] == '?') cnt++;
			else cnt--;
			if (cnt < 0) b = false;
			B[i][j].X = b;
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		bool b = true;
		ll cnt = 0;
		for (int j = i; j >= 0; j--) {
			if (s[j] == ')' || s[j] == '?') cnt++;
			else cnt--;
			if (cnt < 0) b = false;
			B[j][i].Y = b;
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if ((j - i) % 2 == 1 && B[i][j].X && B[i][j].Y) ans++;
		}
	}

	cout << ans << endl;
	return 0;
}