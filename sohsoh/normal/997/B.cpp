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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	set<ll> x;
	x.insert(0);
	vector<ll> ans_s;
	ans_s.push_back(0);
	for (int i = 0; i < 20; i++) {
		set<ll> new_st;
		for (ll e : x) new_st.insert(e + 1), new_st.insert(e + 5), new_st.insert(e + 10), new_st.insert(e + 50);
		x = new_st;
		ans_s.push_back(x.size());
	}

	ll n;
	cin >> n;
	if (n < ans_s.size()) cout << ans_s[n] << endl;
	else cout << ans_s.back() + (n - 20) * 49 << endl;
	return 0;
}