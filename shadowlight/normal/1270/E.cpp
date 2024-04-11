#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector <pair <int, int> > a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	for (int val = 2; val < (1 << 30); val *= 2) {
		vector <int> res;
		int tet;
		for (int i = 0; i < n; i++) {
			int x = a[i].first, y = a[i].second;
			int now = ((x + y) % val + val) % val;
			if (i) {
				if (now == tet) {
					res.push_back(i);
				}
			} else {
				tet = now;
				res.push_back(i);
			} 
		}
		if (res.size() != n && res.size()) {
			cout << res.size() << "\n";
			for (int x : res) {
				cout << x + 1 << " ";
			}
			cout << "\n";
			return 0;
		}
		res.clear();
		tet = 0;
		for (int i = 0; i < n; i++) {
			int x = a[i].first, y = a[i].second;
			int now = (x % val + val) % val;
			if (i) {
				if (now == tet) {
					res.push_back(i);
				}
			} else {
				tet = now;
				res.push_back(i);
			} 
		}
		if (res.size() != n && res.size()) {
			cout << res.size() << "\n";
			for (int x : res) {
				cout << x + 1 << " ";
			}
			cout << "\n";
			return 0;
		}
	}
	assert(false);
}