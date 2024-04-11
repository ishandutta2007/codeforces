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
	ll k, a, b;
	cin >> k >> a >> b;
	if ((a < k && b < k && (a || b)) || (a < k && b % k != 0) || (b < k && a % k != 0)) {
		cout << -1 << endl;
	}
	else {
		cout << (a / k + b / k) << endl;
	}
	exit(0);
}