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
	int N, K;
	cin >> N >> K;
	vector<ll> dur(N);
	ll tot = 0;
	rep(i,0,N) cin >> dur[i], tot += dur[i];
	if (tot % K != 0) {
		cout << "No" << endl;
		return 0;
	}
	tot /= K;
	int i = 0;
	vi re;
	rep(j,0,K) {
		ll su = 0;
		int co = 0;
		while (su < tot) {
			su += dur[i];
			i++;
			co++;
		}
		if (su > tot) {
			cout << "No" << endl;
			return 0;
		}
		re.push_back(co);
	}
	cout << "Yes" << endl;
	trav(x, re) cout << x << ' ';
	cout << endl;
}