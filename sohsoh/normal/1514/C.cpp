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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	if (n == 2) return cout << 1 << endl << 1 << endl, 0;

	vector<int> ans = {1};
	for (int i = 2; i < n - 1; i++)
		if (__gcd(i, n) == 1) ans.push_back(i);
	ll p = 1;
	for (int e : ans) p = p * e % n;
	if (p == n - 1) ans.push_back(n - 1);

	cout << ans.size() << endl;
	for (int e : ans) cout << e << sep;
	cout << endl;
	return 0;
}