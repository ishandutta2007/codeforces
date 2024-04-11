#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define trav(a, x) for (auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool run() {
	ll X, D;
	cin >> X >> D;
	int ds = 0;
	while (X % D == 0) {
		X /= D;
		ds++;
	}

	if (ds == 1) return false;

	for (ll r = 2; r*r <= X; r++) {
		if (X % r == 0) {
			return true;
		}
	}

	// ll reald = D;

	map<ll, int> pr;
	for (ll r = 2; r*r <= D; r++) {
		while (D % r == 0) {
			D /= r;
			pr[r]++;
		}
	}
	if (D != 1) pr[D]++;

	if (sz(pr) == 1 && pr.begin()->second == 1) {
		return false;
	}

	if (ds == 2) {
		return false;
	}

	if (ds >= 4 || X == 1) return true;

	if (sz(pr) == 1 && pr.begin()->second == 2 && pr.begin()->first == X) {
		return false;
	}

	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	rep(i,0,N) {
		cout << (run() ? "YES" : "NO") << endl;
	}
}