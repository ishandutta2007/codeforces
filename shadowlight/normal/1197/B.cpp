#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <int> a(n), pos(n);
	int l, r;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pos[a[i] - 1] = i;
		if (a[i] == n) {
			l = r = i;
		}
	}
	for (int i = n - 2; i >= 0; i--) {
		if (pos[i] == l - 1) {
			l--;
		} else 
		if (pos[i] == r + 1) {
			r++;
		} else {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}