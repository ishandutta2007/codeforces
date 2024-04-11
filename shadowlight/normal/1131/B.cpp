#include <bits/stdc++.h>
#define ll long long

using namespace std;

int calc(int a, int b, int x, int y) {
	if (a > b) {
		swap(a, b);
		swap(x, y);
	}
	int res = 0;
	if (a < b && min(x, y) >= b) {
		res++;
		a = b;
	}
	if (a == b) {
		res += min(x, y) - a;
	}
	return res;
}

int main() {
//	freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a = 0, b = 0;
	int res = 1;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		res += calc(a, b, x, y);
		a = x, b = y;
	}
	cout << res << "\n";
}