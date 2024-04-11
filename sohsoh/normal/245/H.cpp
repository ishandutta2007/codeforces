#include <bits/stdc++.h>
 
using namespace std;
 
typedef int ll;
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

const ll MAXN = 5e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bool is_pal[MAXN][MAXN] = {false};
ll n, pal_L[MAXN][MAXN], ans[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++) is_pal[i][i] = 1;
	for (int i = 0; i < n - 1; i++) if (s[i] == s[i + 1]) is_pal[i][i + 1] = 1;
	for (int sz = 2; sz < n; sz++) {
		for (int L = 0; L < n - sz; L++) if (s[L] == s[L + sz]) is_pal[L][L + sz] = is_pal[L + 1][L + sz - 1];
	}

	for (int L = 0; L < n; L++) {
		pal_L[L][L] = 1;
		for (int R = L + 1; R < n; R++) pal_L[L][R] = pal_L[L][R - 1] + is_pal[L][R];
	}

	for (int R = 0; R < n; R++) {
		ans[R][R] = 1;
		for (int L = R - 1; L >= 0; L--) ans[L][R] = ans[L + 1][R] + pal_L[L][R];
	}

	ll q;
	cin >> q;
	while (q--) {
		ll L, R;
		cin >> L >> R;
		cout << ans[L - 1][R - 1] << endl;
	}

	return 0;
}