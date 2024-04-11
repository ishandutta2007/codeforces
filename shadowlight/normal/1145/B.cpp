#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool bad(int x) {
	return x == 9 || x == 7;
}

int main() {
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int x = n / 10, y = n % 10;
	if (bad(x) || bad(y) || x == 2 || (x == 1 && y != 2) || y == 1) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
}