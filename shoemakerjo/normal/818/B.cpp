#include <iostream>
#include <set>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int a[n+1];
	for (int i = 0; i <= n; i++) {
		a[i] = 0;
	}
	int l[m];
	for (int i = 0; i < m; i++) {
		cin >> l[i];
	}
	bool ok = true;
	for (int i = 1; i < m; i++) {
		int diff = l[i]-l[i-1];
		if (diff <= 0) diff+=n;
		if (a[l[i-1]] > 0 && diff!= a[l[i-1]]) ok = false;
		a[l[i-1]] = diff;
	}
	int pt = 1;
	
	set<int> seen;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) continue;
		if (seen.find(a[i])!=seen.end()) {
			ok = false;
		}
		seen.insert(a[i]);
	}
	if (!ok) cout << -1 << endl;
	else {
		for (int i = 1; i <= n; i++) {
		if (i > 1) cout << " ";
		if (a[i] == 0) {
			while (seen.find(pt)!=seen.end()) {
				pt++;
			}
			cout << pt;
			pt++;
		}
		else cout << a[i];
		}
		cout << endl;
	}
	
	
	// cin >> n;
}