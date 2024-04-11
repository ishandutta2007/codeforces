#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <int> a;
int n;

const int INF = 1e9 + 7;

int try_(int x) {
	int d = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != x) {
			if (d && d != abs(x - a[i])) {
				return INF;
			}
			d = abs(x - a[i]);
		}
	}
	return d;
}

int main() {
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if (a[0] == a[n - 1]) {
		cout << "0\n";
		return 0;
	}
	int res = INF;
	res = min(res, try_(a[0]));
	res = min(res, try_(a[n - 1]));
	res = min(res, try_((a[0] + a[n - 1]) / 2));
	cout << (res == INF ? -1 : res) << "\n";
}