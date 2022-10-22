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

bool ok[MAXN], nice[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> ok[i];
	for (int i = 1; i < (n + 1) / 2; i++) {
		if (n % i) continue;
		for (int j = 0; j < i; j++) nice[j] = ok[j];
		for (int j = i; j < n; j++) nice[j] = nice[j - i] & ok[j];
		for (int j = n - 1; j >= n - i; j--) if (nice[j]) return cout << "YES" << endl, 0;
	}

	cout << "NO" << endl;
	return 0;
}