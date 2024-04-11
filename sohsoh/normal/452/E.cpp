#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll LOG = 20;
const ll MOD = 1e9 + 7;

int ind, Rank[MAXN][LOG], P[MAXN], n, par[MAXN];
ll A[MAXN], B[MAXN], C[MAXN], ans, fans[MAXN];
vector<int> vec[MAXN], F[MAXN];
string a, b, c, s;

inline bool cmp(int i, int j) {
	if (Rank[i][ind - 1] != Rank[j][ind - 1])
		return Rank[i][ind - 1] < Rank[j][ind - 1];
	if (max(i, j) + (1 << (ind - 1)) >= n) return i > j;
	return Rank[i + (1 << (ind - 1))][ind - 1] < Rank[j + (1 << (ind - 1))][ind - 1];
}

inline void build() {
	for (int i = 0; i < n; i++) Rank[i][0] = s[i], P[i] = i;
	for (ind = 1; ind < LOG; ind++) {
		sort(P, P + n, cmp);
		Rank[P[0]][ind] = 0;
		for (int i = 1; i < n; i++)
			Rank[P[i]][ind] = Rank[P[i - 1]][ind] + cmp(P[i - 1], P[i]);
	}
}

inline int LCP(int i, int j) {
	int ans = 0;
	for (ind = LOG - 1; ind >= 0; ind--) {
		if (Rank[i][ind] == Rank[j][ind]) {
			ans += (1 << ind);
			i += (1 << ind);
			j += (1 << ind);
		}
	}

	return ans;
}

inline void merge(int a, int b) {
	a = par[a], b = par[b];
	if (a == b) return;	
	if (F[a].size() < F[b].size()) swap(a, b);

	ans -= A[a] * B[a] * C[a];
	ans -= A[b] * B[b] * C[b];
	A[a] += A[b], B[a] += B[b], C[a] += C[b];
	ans += A[a] * B[a] * C[a];

	for (int e : F[b]) {
		par[e] = a;
		F[a].push_back(e);
	}

	F[b].clear();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> a >> b >> c;
	s = a + "0" + b + "1" + c + "2";
	n = s.size();

	build();
	for (int i = 0; i < n - 1; i++)
		vec[LCP(P[i], P[i + 1])].push_back(i);

	for (int i = 0; i < n; i++) {
		par[i] = i;
		F[i].push_back(i);

		if (P[i] < a.size()) A[i] = 1;
		if (P[i] >= a.size() + 1 && P[i] < a.size() + 1 + b.size()) B[i] = 1;
		if (P[i] >= a.size() + b.size() + 2 && P[i] < n - 1) C[i] = 1;
	}

	for (int i = n; i > 0; i--) {
		for (int e : vec[i])
			merge(e, e + 1);
		fans[i] = (ans % MOD);
	} 

	for (int i = 1; i <= min({a.size(), b.size(), c.size()}); i++) cout << fans[i] << sep;
	cout << endl;
	return 0;
}