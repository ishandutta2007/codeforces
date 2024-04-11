#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int delta = 0;
	int N;
	cin >> N;
	const int inf = 1 << 29;
	int mi = -inf;
	int ma = inf;
	rep(i,0,N) {
		int by, div;
		cin >> by >> div;
		if (div == 1) {
			// x + delta >= 1900
			// x >= 1900 - delta
			mi = max(mi, 1900 - delta);
		}
		else {
			// x + delta <= 1899
			ma = min(ma, 1899 - delta);
		}
		delta += by;
	}
	if (mi > ma) {
		cout << "Impossible" << endl;
	}
	else if (ma == inf) {
		cout << "Infinity" << endl;
	}
	else {
		cout << ma + delta << endl;
	}
	exit(0);
}