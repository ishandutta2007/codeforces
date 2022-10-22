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
	vector <int> r(n);
	for (int i = 0; i < n; ++i) {
		cin >> r[i];
	}
	int m;
	cin >> m;
	vector<int> b(m);
	for (int j = 0; j < m; ++j) {
		cin >> b[j];
	}

	int sumr = 0;
	int maxv = 0;
	
	for (int i = 0; i <= n; ++i) {
		int sumb = 0;
		for (int j = 0; j <= m; ++j) {
			if (sumr + sumb > maxv) {
				maxv = sumr + sumb;
			}
			if (j < m) sumb += b[j];
		}
		if (i < n) sumr += r[i];
	}
	cout << maxv << "\n";
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		solve();
	}

}