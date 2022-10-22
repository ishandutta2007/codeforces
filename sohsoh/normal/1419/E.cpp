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

bool is_prime(ll n) {
	if (n == 1) return false;
	ll sq = sqrt(n);
	for (int i = 2; i <= sq; i++) if (n % i == 0) return false;
	return true;
}

ll C[MAXN];
bool mark[MAXN] = {false};

ll solve() {
	ll n;
	cin >> n;
	ll sq = sqrt(n);
	set<ll> div;
	vector<ll> pf;
	for (ll i = 1; i <= sq; i++) {
		if (n % i == 0) {
			div.insert(i);
			if (is_prime(i)) pf.push_back(i);
			if (n / i != i) {
				div.insert(n / i);
				if (is_prime(n / i)) pf.push_back(n / i);
			}	
		}
	}

	div.erase(1);

	if (pf.size() == 1) {
		for (ll e : div) cout << e << sep;
		cout << endl << 0 << endl;
		return 0;
	}

	if (pf.size() == 2) {
		cout << pf[0] << sep;
		div.erase(pf[0]);
		div.erase(pf[1]);

		if (div.size() == 1) {
			cout << *div.begin() << sep;
			cout << pf[1] << sep;
			cout << endl << 1 << endl;
		} else {
			ll x0 = 0, x1 = 0;
			for (ll e : div) if (e % pf[0] == 0 && e % pf[1] == 0) {
				if (x0 == 0) x0 = e;
				else if (x1 == 0) x1 = e;
			} 	

			div.erase(x0);
			div.erase(x1);
				
			vector<ll> divv;
			for (ll e : div) divv.push_back(e);
			for (int i = 0; i < divv.size(); i++) if (divv[i] % pf[0] == 0) cout << divv[i] << sep, mark[i] = true;	
			cout << x0 << sep;
			cout << pf[1] << sep;
			for (int i = 0; i < divv.size(); i++) if (!mark[i]) cout << divv[i] << sep;
			cout << x1 << endl << 0 << endl;
			fill(mark, mark + divv.size() + 10, false);
		}

		return 0;
	}

	vector<ll> v;
	for (ll e : pf) {
		div.erase(e);
		v.push_back(e);
	}

	for (ll i = 0; i < v.size() - 1; i++) {
		C[i] = v[i] * v[i + 1];
		div.erase(C[i]);
	}

	C[v.size() - 1] = v[0] * v[v.size() - 1];
       	div.erase(C[v.size() - 1]);
		
	vector<ll> divv;
	for (ll e : div) divv.push_back(e);

	ll ind = 0;
	for (ll e : v) {
		cout << e << sep;	
		for (int i = 0; i < divv.size(); i++) {
			if (!mark[i] && divv[i] % e == 0) {
				mark[i] = true;
				cout << divv[i] << sep;
			}
		}	
		cout << C[ind] << sep;
		ind++;
	}	

	cout << endl << 0 << endl;	
	fill(mark, mark + divv.size() + 10, false);
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}