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

ll s1, s2, s3, n1, n2, n3;
multiset<ll> st1, st2, st3;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n1 >> n2 >> n3;
	for (int i = 0; i < n1; i++) {
		int x;
		cin >> x;
		st1.insert(x);
		s1 += x;
	}

	for (int i = 0; i < n2; i++) {
		int x;
		cin >> x;
		st2.insert(x);
		s2 += x;
	}

	for (int i = 0; i < n3; i++) {
		int x;
		cin >> x;
		st3.insert(x);
		s3 += x;
	}

	ll ans = s1 + s2 + s3;
	ll fans = ans - 2 * min({s1, s2, s3});
	ll F = min({*st1.begin() + *st2.begin(), *st1.begin() + *st3.begin(), *st2.begin() + *st3.begin()});
	fans = max(fans, ans - 2 * F);
	cout << fans << endl;
	return 0;
}