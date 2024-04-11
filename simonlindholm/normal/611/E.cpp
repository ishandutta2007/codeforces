#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

int solve(int usea, int useb, int usec, int useab, int useac, int usebc) {
	int res = 0, time = 0;
	auto use = [&time](int& x) {
		if (x >= time) x -= time, time = 0;
		else time -= x, x = 0;
	};

	// BC
	res += usebc;
	time = usebc;
	use(usea);

	// AC
	res += useac;
	time = useac;
	use(useb);
	use(usea);

	// AB
	res += useab;
	time = useab;
	use(usec);
	use(useb);
	use(usea);

	return res + max(usec, max((useb + usec + 1) / 2, (usea + useb + usec + 2) / 3));
}

int main() {
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	int a, b, c;
	cin >> a >> b >> c;
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
	int all = 0;
	int usea = 0, useb = 0, usec_ = 0, useab_ = 0, useac = 0, usebc = 0, either = 0;
	rep(i,0,N) {
		int str;
		cin >> str;
		if (str > a + b + c) {
			cout << -1 << endl;
			return 0;
		}
		if (str > b + c) { // needs all
			all++;
			continue;
		}
		if (str <= a) { usea++; continue; }
		if (str <= b) { useb++; continue; }
		if (str <= c) {
			if (str <= a + b) { either++; continue; }
			else { usec_++; continue; }
		}
		if (str <= a + b) { useab_++; continue; }
		if (str <= a + c) { useac++; continue; }
		if (str <= b + c) { usebc++; continue; }
		assert(0);
	}
	int ans = 1 << 29;
	rep(it,0,either+1) {
		int usec = usec_ + it;
		int useab = useab_ + (either - it);
		ans = min(ans, all + solve(usea, useb, usec, useab, useac, usebc));
	}
	cout << ans << endl;
}