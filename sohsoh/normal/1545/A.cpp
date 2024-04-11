// Sohsoh84 :)
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int t, n;
vector<int> v_e, v_o;

inline int solve() {
	v_e.clear();
	v_o.clear();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (i & 1) v_o.push_back(x);
		else v_e.push_back(x);
	}

	sort(all(v_e), greater<int>());
	sort(all(v_o), greater<int>());
	
	for (int i = 1; i <= n; i++) {
		if (i & 1) {
			if (v_o.empty() || (!v_e.empty() && v_e.back() < v_o.back())) return cout << "NO" << endl, 0;
			v_o.pop_back();
		} else {	
			if (v_e.empty() || (!v_o.empty() && v_o.back() < v_e.back())) return cout << "NO" << endl, 0;
			v_e.pop_back();	
		}
	}

	cout << "YES" << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) solve();
	return 0;
}