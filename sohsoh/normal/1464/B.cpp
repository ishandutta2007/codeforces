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

string s;
ll ps1[MAXN], ps0[MAXN], tot1, tot0, x, y;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s;
	cin >> x >> y;
	s = 'M' + s;
	ll n = s.size() - 1;
	vector<int> v;
	
	if (y > x) {
		swap(x, y);
		for (char& c : s) {
			if (c == '1') c = '0';
			else if (c == '0') c = '1';
		}
	}


	ll tans = 0;

	for (int i = 1; i <= n; i++) {
		ps1[i] = ps1[i - 1];
		ps0[i] = ps0[i - 1];
		if (s[i] == '0') tot0++, ps0[i]++, tans += y * ps1[i];
		else if (s[i] == '1') tot1++, ps1[i]++, tans += x * ps0[i];
		else v.push_back(i);
	}
	
	ll ans = 0;
	for (int e : v)
		tans += x * ps0[e] + y * (tot0 - ps0[e]);
	reverse(all(v));

	ans = tans;
	int ind = 1; 
	for (int e : v) {
		tans += ((int)v.size() - ind) * y;
		tans -= (ind - 1) * y;
		tans -= x * ps0[e] + y * (tot0 - ps0[e]);
		tans += y * ps1[e] + x * (tot1 - ps1[e]);
		ans = min(ans, tans);
		ind++;
	}

	cout << ans << endl;
	return 0;
}