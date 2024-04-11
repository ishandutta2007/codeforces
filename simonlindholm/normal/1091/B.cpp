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
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	ll sumx = 0, sumy = 0;
	rep(i,0,N) {
		ll x, y, a, b;
		cin >> x >> y >> a >> b;
		sumx += x + a;
		sumy += y + b;
	}
	cout << (sumx / N) << ' ' << (sumy / N) << endl;
	exit(0);
}