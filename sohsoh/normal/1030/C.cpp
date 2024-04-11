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

vector<int> v;

bool can(int x) {
	int s = 0;
	for (int e : v) {
		s += e;
		if (s == x) s = 0;
		if (s > x) return false;
	}

	if (s) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int s = 0;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		v.push_back(int(c - '0'));
		s += int(c - '0');
	}

	for (int i = 0; i < max(s, 1); i++) if (can(i)) return cout << "YES" << endl, 0;
	cout << "NO" << endl;
	return 0;
}