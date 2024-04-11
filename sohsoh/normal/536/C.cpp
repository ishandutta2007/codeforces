#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int n, max_x, max_y;
bool flag[MAXN];
set<pll> st;
map<pll, vector<int>> mp;
vector<int> X_vec[MAXN], Y_vec[MAXN];

inline void panik() {
	set<pll> st_x, st_y;
	for (int i = 0; i < MAXN; i++) {
		sort(all(X_vec[i]));
		sort(all(Y_vec[i]));

		for (int y : X_vec[i]) {
			while (!st_y.empty() && st_y.begin() -> X <= y) {
				st.erase({st_y.begin() -> Y, st_y.begin() -> X});
				st_y.erase(st_y.begin());
			}

			st_y.insert({y, i});
		}

		for (int x : Y_vec[i]) {
			while (!st_x.empty() && st_x.begin() -> X <= x) {
				st.erase(*st_x.begin());
				st_x.erase(st_x.begin());
			}

			st_x.insert({x, i});
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		max_x = max(max_x, x);
		max_y = max(max_y, y);

		mp[pll(x, y)].push_back(i);
		if (mp[pll(x, y)].size() == 1) {
			st.insert({x, y});
			X_vec[x].push_back(y);
			Y_vec[y].push_back(x);
		}
	}

	panik();
	const ll T = 1000;
	const ld EPS = 1e-12;

	vector<point> vec;
	for (pll e : st)
		vec.push_back(point(ld(T) / e.X, ld(-T) / e.Y));
	sort(all(vec), [] (point a, point b) {
		return a.real() < b.real();
	});

	vector<point> ch;
	for (point e : vec) {
		//cerr << e.real() << sep << e.imag() << endl;
		while (ch.size() > 1) {
			int sz = ch.size();
			point b = ch[sz - 1], a = ch[sz - 2];

			if ((conj(b - a) * (e - b)).imag() > EPS) ch.pop_back();
			else break;
		}

		ch.push_back(e);
	}

	vector<int> ans;
	for (point t : ch) {
		pll e = pll(round(ld(T) / t.real()), round(ld(-T) / t.imag()));
		assert(!mp[e].empty());
		for (int i : mp[e])
			ans.push_back(i);
	}

	sort(all(ans));
	for (int e : ans)
		cout << e << sep;
	cout << endl;
	return 0;
}