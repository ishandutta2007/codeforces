#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int lo = 0;
	int hi = 10000000;
	while (lo < hi) {
		int mid = (lo+hi)/2;
		int ac = mid/2;
		int bc = mid/3;
		int et = mid/6;
		bool ok = true;
		if (ac < n) ok = false;
		if (bc < m) ok = false;
		if (n + m > ac + bc - et) ok = false;
		if (ok) {
			hi = mid;
		}
		else lo = mid+1;
	}
	cout << lo << endl;
	cin >> n;
}