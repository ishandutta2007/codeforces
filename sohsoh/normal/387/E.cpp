#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pll;

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

int n, A[MAXN], m, fen[MAXN], pos[MAXN];
bool used[MAXN];
pll seg[MAXN];
ll ans;

inline void Add(int ind, int val) {
	for (++ind; ind < MAXN; ind += ind & -ind) fen[ind] += val;
}

inline int Sum(int ind) {
	int ans = 0;
	for (++ind; ind > 0; ind -= ind & -ind) ans += fen[ind];
	return ans;
}

inline int Sum(int L, int R) {
	return Sum(R) - Sum(L - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> A[i], pos[A[i]] = i;
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		used[x] = true;
	}

	vector<pll> v = {{-1, 0}};
	for (int i = 1; i <= n; i++) {
		if (!used[A[i]]) {
			auto it = lower_bound(all(v), make_pair(A[i], -1));
			it--;
			seg[A[i]].X = (it -> Y) + 1;
			continue;
		}
		
		while (!v.empty() && v.back().X > A[i]) v.pop_back();
		v.push_back({A[i], i});
	}

	v.clear();
	v.push_back({-1, n + 1});
	for (int i = n; i > 0; i--) {
		if (!used[A[i]]) {
			auto it = lower_bound(all(v), make_pair(A[i], -1));
			it--;
			seg[A[i]].Y = (it -> Y) - 1;	
			continue;
		}
		
		while (!v.empty() && v.back().X > A[i]) v.pop_back();
		v.push_back({A[i], i});
	}
	
	for (int i = 0; i <= n; i++) {
		if (seg[i].X != 0) {
			ans += seg[i].Y - seg[i].X + 1;
			ans -= Sum(seg[i].X, seg[i].Y);
			Add(pos[i], 1);
		}
	}
	cout << ans << endl;
	return 0;
}