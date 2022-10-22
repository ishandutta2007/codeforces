#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector <int> a(n);
	vector <vector <int>> pos(n);
	string res = "";
	for (int i = 0; i < n; ++i) {
		res += '0';
	}

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
		pos[a[i]].pb(i);
	}

	int l = 0, r = n - 1;
	for (int i = 0; i < n; ++i) {
		vector <int> b;
		for (int x : pos[i]) {
			if (l <= x && x <= r) {
				b.pb(x);
			}
		}
		if (!b.size()) break;
		res[n - i - 1] = '1';
		if (b.size() > 1 || (b[0] != l && b[0] != r)) break;
		if (b[0] == l) {
			++l;
		} else {
			--r;
		}
	}
	bool good = true;
	for (int i = 0; i < n; ++i) {
		if (pos[i].size() > 1) {
			good = false;
			break;
		}
	}
	if (good) {
		res[0] = '1';
	}
	cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}