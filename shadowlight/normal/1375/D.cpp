#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 1007;

int mex(vector <int> &a) {
	vector <int> ex(a.size() + 1, 0);
	for (int x : a) {
		ex[x] = true;
	}
	for (int i = 0; ; ++i) {
		if (!ex[i]) {
			return i;
		}
	}
	assert(false);
}

void solve() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector <int> res;
	while (true) {
		while (true) {
			int d = mex(a);
			if (d >= n) break;
			a[d] = d;
			res.pb(d);
		}
		set <int> bad;
		for (int i = 0; i < n; ++i) {
			if (a[i] != i) {
				bad.insert(i);
			}
		}
		vector <int> pos(n, 0);
		for (int i = 0; i < n; ++i) {
			pos[a[i]] = i;
		}
		if (bad.size()) {
			int x = *bad.begin();
			bad.erase(x);
			res.pb(pos[x]);
			a[pos[x]] = n;
		} else {
			break;
		}
	}
	cout << res.size() << "\n";
	for (int x : res) {
		cout << x + 1 << " ";
	}
	cout << "\n";

	/*cout << "A\n";
	for (int x : a) {
		cout << x << " ";
	}
	cout << "\n";*/

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