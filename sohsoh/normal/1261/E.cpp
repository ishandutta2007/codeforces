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

int n;
vector<pll> v, vt;
vector<vector<bool>> ans, ans2;

inline void Majik(int L, int R) {
	vt = v;
	int ptr = R;
	for (int i = L; i <= R; i++) {
		ans.push_back({});
		ans.rbegin() -> resize(n);
		for (int j = L; j <= min(R, n - 1); j++) {
			if (v[j].X >= i - L)
				ans[i][j] = 1;
		}

		for (int j = R + 1; j < n; j++) {
			if (v[j].X > 1) {	
				ans[i][j] = 1;
				v[j].X--;
			}
		}
	}

	for (int i = min(R, n - 1); i >= L; i--) {
		ptr = min(ptr, L + v[i].X + 1);
		ans[ptr][i] = 0;
		ptr--;
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back({x, i});
	}

	sort(all(v));
	int L = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].X < i + 1 - L) {
			Majik(L, i);
			L = i + 1;			
		}
	}

	Majik(L, n);

	for (int i = 0; i < (int)ans.size(); i++) {
		if (find(all(ans[i]), true) == ans[i].end()) continue;
		ans2.push_back({});
		ans2.rbegin() -> resize(n);
		for (int j = 0; j < n; j++)
			ans2[ans2.size() - 1][v[j].Y] = ans[i][j];
	}

	
	cout << ans2.size() << endl;
	for (auto e : ans2) {
		for (auto e2 : e) {
			cout << int(e2);
		}

		cout << endl;
	}
	return 0;
}