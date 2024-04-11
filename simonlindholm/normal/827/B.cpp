#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int res;
vector<pii> eds;
void go(int N, int K) {
	if (N == K) {
		if (K == 1) {
			return;
		}
		assert(K == 2);
		res++;
		eds.emplace_back(0, 1);
		return;
	}
	if (N == K+1) {
		res += 2;
		rep(i,0,K) eds.emplace_back(0, i+1);
		return;
	}

	res += 2;
	int at = N-K, origat = at;
	rep(i,0,K) {
		if (at >= 2 || (origat == 2 && at >= 1)) --at;
		eds.emplace_back(N-1 - i, at);
	}
	go(N-K, origat - at);
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N, K;
	cin >> N >> K;
	go(N, K);
	cout << res << endl;
	trav(pa, eds) cout << pa.first+1 << ' ' << pa.second+1 << endl;
	exit(0);
}