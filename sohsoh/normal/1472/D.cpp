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

int n;

inline int solve() {
	priority_queue<int> E, O;
	ll A = 0, B = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x & 1) O.push(x);
		else E.push(x);
	}

	bool turn = true;
	while (E.size() + O.size()) {
		if (turn) {
			if (O.empty()) A += E.top(), E.pop();
			else if (E.empty()) O.pop();
			else {
				int e = E.top(), o = O.top();
				if (o <= e) A += e, E.pop();
				else O.pop();
			}
		} else {	
			if (E.empty()) B += O.top(), O.pop();
			else if (O.empty()) E.pop();
			else {
				int e = E.top(), o = O.top();
				if (o >= e) B += o, O.pop();
				else E.pop();
			}		
		}

		turn = !turn;
	}

	if (A == B) return cout << "Tie" << endl, 0;
	if (A > B) return cout << "Alice" << endl, 0;
	cout << "Bob" << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}