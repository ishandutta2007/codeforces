#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	if (m > n / 2) {
		cout << n - m << "\n";
	} else {
		cout << max(m, 1) << "\n";
	}
}