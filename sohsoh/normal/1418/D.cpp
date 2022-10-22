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

set<ll> st;
multiset<ll> LR;

void print_ans() {
	if (st.size() < 3) {
		cout << 0 << endl;
		return;
	}
	
	ll mx = *st.rbegin(), mn = *st.begin();
	ll ans = mx - mn - (*LR.rbegin());
	//auto it = st.rbegin();
	//it--;
	//ans = min(ans, (*it) - mn);
	//auto it2 = st.begin();
	//it2++;
	//ans = min(ans, mx - (*it2));
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, q;
	cin >> n >> q;
	while (n--) {
		ll x;
		cin >> x;
		st.insert(x);
	}
	
	for (auto it = st.begin(); it != st.end(); it++) {
		auto it2 = it;
		it2++;
		if (it2 == st.end()) break;
		LR.insert(*it2 - *it);
	}
	
	print_ans();	
	while (q--) {
		ll tp, x;
		cin >> tp >> x;
		if (tp == 0) {
			auto it = st.find(x);
			auto it2 = it;
			it2++;
			if (it2 != st.end()) LR.erase(LR.find((*it2) - (*it)));
			auto it3 = it;
			if (it != st.begin()) {
				it3--;
				LR.erase(LR.find((*it) - (*it3)));
				if (it2 != st.end()) LR.insert((*it2) - (*it3));
			}

			st.erase(x);
		} else {
			auto it = st.lower_bound(x);
			if (it != st.begin()) {
				auto it2 = it;
				it2--;
				if (it != st.end()) LR.erase(LR.find(*it - *it2));
				LR.insert(x - *it2);
			}

			if (it != st.end()) LR.insert(*it - x);
			st.insert(x);
		}

		print_ans();
	}
	return 0;
}