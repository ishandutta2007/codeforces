#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

const ll MAXN = 2e7 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int SPF[MAXN];
ll c, d, x, T[MAXN];

vector<int> Div(ll n) {
	vector<int> ans = {1};
	while (n > 1) {
		int s = SPF[n], cnt = 0;
		while (n % s == 0) n /= s, cnt++;
		int sz = ans.size(), t = s;
		for (int i = 1; i <= cnt; i++) {
			for (int j = 0; j < sz; j++)
				ans.push_back(t * ans[j]);
			
			t = t * s;
		}
	}

	return ans;
}

inline ll Ans(int g) {
	ll L = d * g + x;
	if (L % c) return 0;
	L /= c;
	if (L <= 0) return 0;
	if (L % g) return 0;
	return T[L / g];
}

inline int solve() {
	cin >> c >> d >> x;
	ll ans = 0;

	vector<int> D = Div(x);
	for (int e : D) {
		ans += Ans(e);
	}

	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 1; i < MAXN; i++) SPF[i] = i;
	for (int i = 1; i < MAXN; i++) T[i] = 1;
	
	for (int i = 2; i < MAXN; i++) {
		if (SPF[i] == i) {
			for (int j = i; j < MAXN; j += i) {	
				if (SPF[j] == j) SPF[j] = i;
				T[j] *= 2;
			}
		}
	}


	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}