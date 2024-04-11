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
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll o = 0, e = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		if (x == 1) o++;
		else e++;
	}

	if (o == 0) for (int i = 0; i < n; i++) cout << 2 << sep;
	else if (e == 0) for (int i = 0; i < n; i++) cout << 1 << sep;
	else {
		cout << 2 << sep << 1 << sep;
		e--;
		o--;
		for (int i = 0; i < e; i++) cout << 2 << sep;
		for (int i = 0; i < o; i++) cout << 1 << sep;
	}

	cout << endl;
	return 0;
}