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

ll n;
map<ll, ll> mp;

vector<ll> e_r[MAXN], s_r[MAXN], e_b[MAXN], s_b[MAXN];
multiset<ll> blue, red;

int main() {
//	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<pll> r, b;
	vector<ll> pnt;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll l, R, c;
		cin >> l >> R >> c;
		if (c == 1) r.push_back({l, R});
	      	else b.push_back({l, R});
		pnt.push_back(l);	
		pnt.push_back(R);	
	} 

	sort(all(pnt));
	ll ind = 1;
	for (ll e : pnt) {
		if (mp.find(e) != mp.end()) continue;
		mp.insert({e, ind});
		ind++;
	}

	for (int i = 0; i < r.size(); i++) r[i] = {mp[r[i].X], mp[r[i].Y]};
	for (int i = 0; i < b.size(); i++) b[i] = {mp[b[i].X], mp[b[i].Y]};
	for (pll e : r) {
		s_r[e.X].push_back(e.Y);
		e_r[e.Y].push_back(e.X);
	}

	for (pll e : b) {
		s_b[e.X].push_back(e.Y);
		e_b[e.Y].push_back(e.X);
	}

	ll mch = 0;
	for (int i = 0; i < 3 * n; i++) {
		for (ll e : s_r[i]) red.insert(e);
		for (ll e : s_b[i]) blue.insert(e);
		while (!red.empty() && *red.begin() == i) {
			if (!blue.empty()) blue.erase(blue.begin()), mch++;	
			red.erase(red.begin());	
		}

		while (!blue.empty() && *blue.begin() == i) {
			if (!red.empty()) red.erase(red.begin()), mch++;
			blue.erase(blue.begin());
		}
	}
	
	cout << n - mch << endl;
	return 0;
}