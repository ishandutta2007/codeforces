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

const ll MAXN = 70000 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bitset<MAXN> B[2], tmp;
vector<pll> v;
int n, F[MAXN], s, A[MAXN];
bool is_in[MAXN];
vector<int> ans[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v.push_back({x, i});
		A[i] = x;
	}

	sort(all(v), greater<pll>());
	B[0][v[0].X] = true;
	F[v[0].X] = v[0].Y;
	for (int i = 1; i < n; i++) {
		int r = i & 1;
		B[r] = B[1 - r] | (B[1 - r] << v[i].X);
		tmp = B[r] ^ B[1 - r];
		for (int j = tmp._Find_first(); j < tmp.size(); j = tmp._Find_next(j)) F[j] = v[i].Y;
	}
	
	if (!B[0][s] && !B[1][s]) return cout << -1 << endl, 0;
	while (s) {
		is_in[F[s]] = true;
		s -= A[F[s]];
	}

	int lst = v[0].Y;
	for (pll e : v) 
		if (!is_in[e.Y])
			ans[lst].push_back(e.Y), lst = e.Y;
	for (int i = 1; i <= n; i++) {
		if (ans[i].empty()) cout << A[i] << sep << 0 << endl;
		else cout << A[i] - A[ans[i][0]] << sep << 1 << sep << ans[i][0] << endl;
	}
	return 0;
}