#include <bits/stdc++.h>
using namespace std;

long long cal(long long ma, long long mb, long long mc, long long sa, long long sb, long long sc) {
	return max(sa - mb - mc + sc - mc + sb - mb, max(sa - sb + sc, sa - sc + sb));
}

int main() {
//	freopen("in.txt", "r", stdin);
	long long a, b, c, ma, mb, mc, sa, sb, sc, i, ra, rb, rc;
	ma = mb = mc = 0x3f3f3f3f;
	sa = sb = sc = 0;
	cin >> a >> b >> c;
	while (a--) {
		cin >> i;
		ma = min(ma, i);
		sa += i;
	}
	while (b--) {
		cin >> i;
		mb = min(mb, i);
		sb += i;
	}
	while (c--) {
		cin >> i;
		mc = min(mc, i);
		sc += i;
	}
	ra = cal(ma, mb, mc, sa, sb, sc);
	rb = cal(mb, mc, ma, sb, sc, sa);
	rc = cal(mc, ma, mb, sc, sa, sb);
	cout << max(ra, max(rb, rc)) << endl;
	return 0;
}