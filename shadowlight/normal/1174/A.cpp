#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	n *= 2;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if (a[0] != a.back()) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		return 0;
	} else {
		cout << "-1\n";
		return 0;
	}
}