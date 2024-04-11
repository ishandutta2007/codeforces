#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	vi v(N), dtime(N);
	rep(i,0,N) cin >> v[i];
	int cur = 0;
	rep(i,0,N) {
		cur++;
		cur = min(cur, v[i]);
		dtime[i] = cur;
	}
	cur = 0;
	int res = 0;
	for (int i = N-1; i >= 0; --i) {
		cur++;
		cur = min(cur, v[i]);
		res = max(res, min(cur, dtime[i]));
	}
	cout << res << endl;
}