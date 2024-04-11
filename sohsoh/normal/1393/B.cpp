/*
    Soheil Mohammadkhani
    final test contest on vim
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

ll mp[MAXN] = {0};
ll m8 = 0, m6 = 0, m4 = 0, m2 = 0;

int main() {
	fast_io;
	ll n;
	cin >> n;
//	map<ll, ll> mp;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
	//	if (mp.find(x) == mp.end()) mp.insert({x, 0});
		mp[x]++;
	} 

	for (int i = 0; i < MAXN; i++) {
		if (mp[i] > 7) m8++;
		else if (mp[i] > 5) m6++;
		else if (mp[i] > 3) m4++;
		else if (mp[i] > 1) m2++;
	}

	ll q, t = 0;
	cin >> q;
	while (q--) {
		t++;
		char c;
		cin >> c;
		ll x;
		cin >> x;
		if (c == '+') {
			mp[x]++;
			if (mp[x] == 8) m6--, m8++;
		       	if (mp[x] == 6) m4--, m6++;
			if (mp[x] == 4) m2--, m4++;
			if (mp[x] == 2) m2++;	
		} else {
			mp[x]--;
			if (mp[x] == 7) m8--, m6++;
			else if (mp[x] == 5) m6--, m4++;
			else if (mp[x] == 3) m4--, m2++;
			else if (mp[x] == 1) m2--;
		}

		//if (n == 90000 && t == 3) cout << m8 << sep << m6 << sep << m4 << sep << m2 << endl;

		if (m8) {
			cout << "YES" << endl;
			continue;
		}

		if (m6) {
			if (m6 > 1 || m4 > 0 || m2 > 0) cout << "YES" << endl;
			else cout << "NO" << endl;
			continue;
		}

		if (m4 <= 0) {
			cout << "NO" << endl;
			continue;
		}

		if (m4 > 1) cout << "YES" << endl;
		else if (m2 > 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}