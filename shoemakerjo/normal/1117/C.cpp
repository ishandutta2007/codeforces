#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int maxn = 100010;
int n;

ll xdiff[maxn];
ll ydiff[maxn];
string s;
ll x1, y1, x2, y2;

bool check(ll mid) {

	ll numrounds = mid / n;
	int numleft = mid % n;


	ll xc = x1 + numrounds * xdiff[n] + xdiff[numleft];
	ll yc = y1 + numrounds * ydiff[n] + ydiff[numleft];

	ll cdist = abs(xc - x2) + abs(yc - y2);

	return cdist <= mid;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> n >> s;
	s = " " + s;
	for (int i = 1; i <= n; i++) {
		xdiff[i] = xdiff[i-1];
		ydiff[i] = ydiff[i-1];
		if (s[i] == 'U') {
			ydiff[i]++;
		}
		if (s[i] == 'D') {
			ydiff[i]--;
		}
		if (s[i] == 'L') {
			xdiff[i]--;
		}
		if (s[i] == 'R') {
			xdiff[i]++;
		}

	}

	ll lo = 0;

	ll hi = 10000000000000000LL;
	ll ohi = hi;

	while (lo < hi) {
		ll mid = (lo + hi)/2;
		if (check(mid)) {
			hi = mid;
		}
		else lo = mid+1;
	}

	if (lo == ohi) {
		cout << -1 << endl;
	}
	else cout << lo << endl;
	
}