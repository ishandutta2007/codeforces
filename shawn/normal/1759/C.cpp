#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int _, l, r, a, b, x;

bool X(int num) {
	return abs(num) >= x;
}

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> _;
	while (_ --) {
		cin >> l >> r >> x >> a >> b;
		int ans = -1;
		if (a == b) ans = 0;
		else if (X(a - b)) ans = 1;
		else {
			// a->l->b t=2
			// a->r->b t=2
			// a->l->r->b t=3
			// a->r->l->b t=3
			if (X(a - l) && X(l - b)) ans = 2;
			else if (X(a - r) && X(r - b)) ans = 2;
			else if (X(a - l) && X(l - r) && X(r - b)) ans = 3;
			else if (X(a - r) && X(r - l) && X(l - b)) ans = 3;
		}
		cout << ans << "\n";
	}
	return 0;	
}