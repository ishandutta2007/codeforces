// Sohsoh84 :)))
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

const ll MAXN = 1e5 + 10;
const ll LOG = 20;

int pw, n, Rank[MAXN][LOG], P[MAXN], A[MAXN], L[MAXN], R[MAXN];
string s;

inline bool cmp(int i, int j) {
	if (Rank[i][pw - 1] != Rank[j][pw - 1]) return Rank[i][pw - 1] < Rank[j][pw - 1];
	if (max(i, j) + (1 << (pw - 1)) > n) return i > j;
	return Rank[i + (1 << (pw - 1))][pw - 1] < Rank[j + (1 << (pw - 1))][pw - 1];
}

inline void build() {
	s = '.' + s;
	for (int i = 1; i <= n; i++) Rank[i][0] = s[i], P[i] = i;
	
	for (pw = 1; pw < LOG; pw++) {
		sort(P + 1, P + n + 1, cmp);
		Rank[P[1]][pw] = 1;
		for (int i = 2; i <= n; i++)
			Rank[P[i]][pw] = Rank[P[i - 1]][pw] + cmp(P[i - 1], P[i]);
	}
}

inline int lcp(int i, int j) {
	int ans = 0;
	for (int k = LOG - 1; k >= 0; k--) {
		if (Rank[i][k] == Rank[j][k]) {
			ans += (1 << k);
			i += (1 << k);
			j += (1 << k);
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s;
	n = s.size();
	build();
	for (int i = 1; i < n; i++) A[i] = lcp(P[i], P[i + 1]);

	for (int i = 1; i < n; i++)
		for (L[i] = i - 1; L[i] && A[i] < A[L[i]]; L[i] = L[L[i]]);
	for (int i = n - 1; i > 0; i--)
		for (R[i] = i + 1; R[i] < n && A[i] <= A[R[i]]; R[i] = R[R[i]]);
	
	ll ans = 1ll * n * (n + 1) / 2;
	for (int i = 1; i < n; i++)
		ans += 1ll * A[i] * (i - L[i]) * (R[i] - i);
	cout << ans << endl;
	return 0;
}