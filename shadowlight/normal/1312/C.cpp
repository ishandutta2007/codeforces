#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
 
using namespace std;
 
vector <ll> st;
const ll INF = 1e16 + 7;
 
ll n, k;
 
void init() {
	st.clear();
	ll now = 1;
	st.pb(now);
	while (now * k < INF) {
		now *= k;
		st.pb(now);
	}
}
 
void solve() {
	cin >> n >> k;
	init();
	ll mask = 0;
	int mx = st.size() - 1;
	bool can = true;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		for (int i = mx; i >= 0; i--) {
			if (x >= st[i]) {
				x -= st[i];
				if (mask & (1LL << i)) {
					can = false;
				}
				mask |= (1LL << i);
			}
		}
		if (x) can = false;
	}
	cout << (can ? "YES\n" : "NO\n");
}
 
 
int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
 
}