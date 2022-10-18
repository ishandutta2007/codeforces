#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int inf = 1 << 29;
int N;
vi a;

int rec(ll as, ll bs, ll W, ll H, int at, bool lasta) {
	if (as >= W && bs >= H) return 0;
	if (at == N)
		return inf;

	ll v = a[at];
	int res = inf;
	if (as < W) {
		res = 1 + rec(as * v, bs, W, H, at+1, true);
	}
	if (bs < H) {
		if (lasta && at > 0 && a[at-1] == v) ;
		else res = min(res, 1 + rec(as, bs * v, W, H, at+1, false));
	}
	return res;
}

int solve(int A, int B, int W, int H) {
	N = sz(a);
	W = (W + A-1) / A;
	H = (H + B-1) / B;
	return rec(1, 1, H, W, 0, false);
	// ~16 width muls, ~16 height muls
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int A, B, H, W, N;
	cin >> A >> B >> H >> W >> N;
	swap(A, H);
	swap(B, W);
	a.resize(N);
	rep(i,0,N) cin >> a[i];
	sort(all(a));
	reverse(all(a));
	if (sz(a) > 50) a.erase(a.begin() + 50, a.end()), N = 50;
	int res = min(solve(A, B, H, W), solve(B, A, H, W));
	if (res >= inf) res = -1;
	cout << res << endl;
	exit(0);
}