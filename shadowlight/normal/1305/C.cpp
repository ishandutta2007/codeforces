#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 2e5 + 7;
const int M = 1007;

int n, m;

ll cnt[M][M];

int power(int a, ll k) {
	if (!k) {
		return 1;
	}
	int b = power(a, k / 2);
	b = b * b % m;
	if (k % 2) {
		return a * b % m;
	} else {
		return b;
	}
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	vector <int> a(n);
	vector <vector <int> > arrs(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		arrs[a[i] % m].push_back(a[i]);
	}
	for (int i = 0; i < m; i++) {
		if (arrs[i].size() >= 2) {
			cout << "0\n";
			return 0;
		}
	}
	int res = 1;
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			if (!arrs[i].size() || !arrs[j].size()) continue;
			//cout << arrs[i].size() << " " << arrs[j].size() << "\n";
			int now = (j - i);
			if (arrs[i][0] > arrs[j][0]) {
				now = m - now;
			}
			//cout << "kek\n";
			res = res * now % m;
		}
	}
	cout << res << "\n";
}