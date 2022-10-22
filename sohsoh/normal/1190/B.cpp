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

map<ll, ll> mp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll s = 0, non_emp = 0;
	vector<ll> A;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		if (mp.find(x) == mp.end()) mp.insert({x, 0});
		mp[x]++;
		A.push_back(x);
	}
	
	vector<ll> v;
	for (pll e : mp) v.push_back(e.Y);
       	sort(all(v));
	if (v.back() > 2 || (v.size() >= 2 && v[v.size() - 1] > 1 && v[v.size() - 2] > 1) || mp[0] > 1) return cout << "cslnb" << endl, 0;
	for (pll e : mp) {
		if (e.Y > 1 && mp.find(e.X - 1) != mp.end() && mp[e.X - 1] > 0) return cout << "cslnb" << endl, 0;
	}	
	
	sort(all(A));
	for (int i = 0; i < n; i++) {
		s += A[i] - i;
	}
	if (s & 1) return cout << "sjfnb" << endl, 0;
	cout << "cslnb" << endl;
	return 0;
}