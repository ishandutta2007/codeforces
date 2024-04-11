#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int M = 30;

const int INF = 1e9 + 7;

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector <int> a(n);
	vector <int> mbit(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int j = M - 1; j >= 0; --j) {
			if (a[i] >= (1 << j)) {
				mbit[i] = j;
				break;
			}
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		if (i && (a[i] ^ a[i + 1]) < a[i - 1]) {
			cout << "1\n";
			return 0;
		}
		if (i < n - 2 && (a[i] ^ a[i + 1]) > a[i + 2]) {
			cout << "1\n";
			return 0;
		}
	}
	int res = INF;
	for (int i = 0; i < n - 1; ++i) {
		int x = 0;
		for (int j = i; j >= 0; --j) {
			x ^= a[j];
			int y = 0;
			for (int k = i + 1; k < n; ++k) {
				y ^= a[k];
				if (x > y) {
					res = min(res, (i - j) + (k - (i + 1)));
				}
			}
		}
	}
	cout << (res == INF ? -1 : res) << "\n";
}