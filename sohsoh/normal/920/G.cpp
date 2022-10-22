#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<int> P_Factors[MAXN];
int M[MAXN];

inline int D(int L, int R, int x) {
	return R / x - L / x;
}

inline int Ans(int n, int p, int x) {
	int MASK = (1 << P_Factors[p].size());
       	ll ans = D(x, n, 1);
	
	for (int i = 1; i < MASK; i++) {
		int t = D(x, n, M[i]);
		if (__builtin_popcount(i) & 1) ans -= t;
		else ans += t;
	}

	return ans;
}

inline int solve() {
	int x, p, k;
	cin >> x >> p >> k;
	int MASK = (1 << P_Factors[p].size());
	M[0] = 1;
	for (int i = 1; i < MASK; i++) {
		int b = __builtin_ctz(i);
		M[i] = M[i ^ (1 << b)] * P_Factors[p][b];
	}

	int L = x + 1, R = 1e9;

	while (L < R) {
		int mid = (L + R) >> 1;
		if (Ans(mid, p, x) < k) L = mid + 1;
		else R = mid;
	}

	cout << L << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 2; i < MAXN; i++) 
		if (P_Factors[i].empty())
			for (int j = i; j < MAXN; j += i)
				P_Factors[j].push_back(i);

	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}