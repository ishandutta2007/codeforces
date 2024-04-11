#include <bits/stdc++.h>
using namespace std;
int n, m, a[109], b[109];
int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	sort(b, b + m);
	for(int i = 0; i < n; i++) {
		if(a[i] == 0) a[i] = b[--m];
	}
	bool f = false;
	for(int i = 1; i < n; i++) if(a[i - 1] > a[i]) f = true;
	cout << (f ? "Yes" : "No") << endl;
	return 0;
}