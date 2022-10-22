/*
    Soheil Mohammadkhani
    OK, im back :)
*/
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
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN];

int main() {
	fast_io;
	ll t;
	cin >> t;
	while (t--) {
		vector<ll> v;
	       	string s;
		cin >> s;
		char p = '2';
		ll cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != p) {
				p = s[i];
				if (p == '0') v.push_back(cnt);
				cnt = 1;
			} else cnt++;
		}

		if (p == '1') v.push_back(cnt);
		sort(all(v));
		bool b = true;
		ll ans = 0;
		while (!v.empty()) {
			if (b) ans += v.back();
			v.pop_back();
			b = !b;
		}

		cout << ans << endl;
	}	
}