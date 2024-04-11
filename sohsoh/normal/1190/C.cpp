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
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

set<ll> B, W;

void draw() {
	cout << "once again" << endl;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == '1') B.insert(i);
		else W.insert(i);
	}

	if (W.empty() || *W.rbegin() - *W.begin() + 1 <= k) return cout << "tokitsukaze" << endl, 0;
	if (B.empty() || *B.rbegin() - *B.begin() + 1 <= k) return cout << "tokitsukaze" << endl, 0;
	bool ok = false;
	for (int i = 0; i <= n - k; i++) {
		if (W.lower_bound(i) != W.begin() && W.lower_bound(i + k) != W.end()) draw();
		if (B.lower_bound(i) != B.begin() && B.lower_bound(i + k) != B.end()) draw();	
		if ((W.lower_bound(i + 1) != W.end() && *W.rbegin() - *W.lower_bound(i + k) + 1 > k) || (W.lower_bound(i) != W.begin() && *(--W.lower_bound(i)) - *W.begin() + 1 > k)) draw();
		if ((B.lower_bound(i + 1) != B.end() && *B.rbegin() - *B.lower_bound(i + k) + 1 > k) || (B.lower_bound(i) != B.begin() && *(--B.lower_bound(i)) - *B.begin() + 1 > k)) draw();
	}

	cout << "quailty" << endl;
	return 0;
}