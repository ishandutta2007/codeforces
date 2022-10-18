#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

int solve(ll lim) {
	int res = 0;
	rep(i,0,62) {
		rep(j,0,i-1) {
			ll b = (1LL << i) - (1LL << j) - 1;
			if (b <= lim) res++;
		}
	}
	return res;
}

int main() {
	cin.sync_with_stdio(false);
	ll A, B;
	cin >> A >> B;
	cout << solve(B) - solve(A-1) << endl;
}