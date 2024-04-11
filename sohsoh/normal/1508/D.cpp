#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, par[MAXN], ind;
vector<pll> ans;
pair<pll, int> A[MAXN];
vector<int> v;

inline ll Cross(pll x, pll y) {
	return 1ll * x.X * y.Y - 1ll * x.Y * y.X;
}

inline bool cmp(int i, int j) {
	return Cross(make_pair(A[ind].X.X - A[i].X.X, A[ind].X.Y - A[i].X.Y), 
			make_pair(A[ind].X.X - A[j].X.X, A[ind].X.Y - A[j].X.Y)) < 0;
}

int Find(int v) {
	if (v == par[v]) return v;
	return par[v] = Find(par[v]);
}

inline void Union(int u, int v) {
	par[Find(u)] = Find(v);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) par[i] = i;
	for (int i = 1; i <= n; i++) cin >> A[i].X.X >> A[i].X.Y >> A[i].Y, Union(i, A[i].Y);
	
	for (int i = 1; i <= n; i++)
		if (A[i].Y != i && (ind == 0 || A[i] < A[ind]))
			ind = i;

	if (!ind) return cout << 0 << endl, 0;
	for (int j = 1; j <= n; j++) 	
		if (j != ind && A[j].Y != j)
			v.push_back(j);
	sort(all(v), cmp);

	for (int i = 0; i < (int) v.size() - 1; i++) {
		if (Find(v[i]) != Find(v[i + 1])) {
			swap(A[v[i]].Y, A[v[i + 1]].Y);
			ans.push_back({v[i], v[i + 1]});
			Union(v[i], v[i + 1]);
		}
	}

	while (A[ind].Y != ind) {
		ans.push_back({ind, A[ind].Y});
		swap(A[ind].Y, A[A[ind].Y].Y);
	}

	cout << ans.size() << endl;
	for (pll e : ans) cout << e.X << sep << e.Y << endl;
	return 0;
}