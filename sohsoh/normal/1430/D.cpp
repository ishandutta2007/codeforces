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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		string s;
		cin >> n >> s;
		vector<ll> v;
		ll cnt = 0;
		for (int i = 0; i < n; i++) {
			if (i > 0 && s[i] != s[i - 1]) {
				v.push_back(cnt);
				cnt = 0;
			}
			cnt++;
		}	

		v.push_back(cnt);
		set<ll> st;
		for (int i = 0; i < v.size(); i++) if (v[i] > 1) st.insert(i);
		ll ind = 0, sz = v.size();
		while (sz) {
			if (sz == 1) {
				ind++;
				break;
			}
			
			if (!st.empty()) {
				v[*st.begin()]--;
				if (v[*st.begin()] <= 1) st.erase(st.begin());
				if (*st.begin() <= ind) st.erase(st.begin());
			} else {
				v.pop_back();
				sz--;
			}
			ind++;
			sz--;
		}

		cout << ind << endl;
	}
	return 0;
}