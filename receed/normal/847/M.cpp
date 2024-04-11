#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef FLOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> a(n);
	cin >> a[0];
	bool f = 1;
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		if (a[i] - a[i - 1] != a[1] - a[0])
			f = 0;
	}
	if (f)
		cout << a[n - 1] + a[1] - a[0];
	else
		cout << a[n - 1];	
}