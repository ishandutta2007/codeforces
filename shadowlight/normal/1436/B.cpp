#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int MAXN = 1e7;

void solve() {
	int n;
	cin >> n;
	int sn = n;
	vector <vector <int>> a(n, vector<int>(n, 0));
	while (n >= 4) {
		for (int i = n - 2; i <= n - 1; ++i) {
			for (int j = n - 2; j <= n - 1; ++j) {
				a[i][j] = 1;
			}
		}
		n -= 2;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = 1;
		}
	}

	for (int i = 0; i < sn; ++i) {
		for (int j = 0; j < sn; ++j) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector <int> prime(MAXN, true);

	for (int i = 2; i < MAXN; ++i) {
		if (prime[i]) {
			for (int j = 2 * i; j < MAXN; j += i) {
				prime[j] = false;
			}
		}
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}