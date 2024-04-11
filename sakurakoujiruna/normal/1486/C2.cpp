#include <bits/stdc++.h>
using namespace std;

int n;
int query(int l, int r, bool rev) {
	if(rev) {
		swap(l, r);
		l = n - l + 1;
		r = n - r + 1;
	}
	cout << "? " << l << ' ' << r << '\n';
	cout.flush();
	int x; cin >> x;
	return (rev ? n - x + 1 : x);
}

int main() {
	cin >> n;
	int x = query(1, n, 0);
	int l, r;
	bool rev;
	
	if(x == 1) {
		l = 2;
		r = n + 1;
		rev = 0;
	} else if(x == n) {
		l = 2;
		r = n + 1;
		rev = 1;
	} else {
		int y = query(1, x, 0);
		if(x == y) {
			l = n - x;
			r = n + 1;
			rev = 1;
		} else {
			l = x + 1;
			r = n + 1;
			rev = 0;
		}
	}
	
	if(rev)
		x = n - x + 1;
	
	while(l + 1 < r) {
		int m = (l + r) / 2;
		if(query(1, m - 1, rev) == x)
			r = m;
		else
			l = m;
	}
	
	cout << "! " << (rev ? n - l + 1 : l) << '\n';
	cout.flush();
}