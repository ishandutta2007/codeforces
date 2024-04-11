#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
class fraction {
public:
	long long p, q;
	fraction() : p(0), q(1) {};
	fraction(long long p_) : p(p_), q(1) {};
	fraction(long long p_, long long q_) : p(q_ > 0 ? p_ : -p_), q(q_ > 0 ? q_ : -q_) {};
	bool operator==(const fraction& fr) {
		return p * fr.q == fr.p * q;
	}
	bool operator<(const fraction& fr) const {
		return p * fr.q < fr.p * q;
	}
	bool operator>(const fraction& fr) const {
		return p * fr.q > fr.p * q;
	}
	bool operator<=(const fraction& fr) const {
		return p * fr.q <= fr.q * p;
	}
	bool operator>=(const fraction& fr) const {
		return p * fr.q >= fr.p * q;
	}
};
int n, xa, ya, xb, yb, sx, sy, vx, vy, ac[200009]; fraction l[100009], r[100009], st[200009];
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> xa >> ya >> xb >> yb;
	for (int i = 0; i < n; i++) {
		cin >> sx >> sy >> vx >> vy;
		fraction xl = (vx == 0 ? 0 : max(fraction(0), fraction(xa - sx, vx)));
		fraction xr = (vx == 0 ? (xa < sx && sx < xb ? inf : 0) : max(fraction(0), fraction(xb - sx, vx)));
		fraction yl = (vy == 0 ? 0 : max(fraction(0), fraction(ya - sy, vy)));
		fraction yr = (vy == 0 ? (ya < sy && sy < yb ? inf : 0) : max(fraction(0), fraction(yb - sy, vy)));
		if (xl > xr) swap(xl, xr);
		if (yl > yr) swap(yl, yr);
		l[i] = (xl > yl ? xl : yl);
		r[i] = (xr < yr ? xr : yr);
		if (l[i] >= r[i]) l[i] = 0, r[i] = 0;
		st[i] = l[i];
		st[i + n] = r[i];
	}
	sort(st, st + 2 * n);
	int sc = unique(st, st + 2 * n) - st;
	for (int i = 0; i < n; i++) {
		ac[lower_bound(st, st + sc, l[i]) - st]++;
		ac[lower_bound(st, st + sc, r[i]) - st]--;
	}
	int sum = 0; bool flag = false;
	for (int i = 0; i < sc; i++) {
		sum += ac[i];
		if (sum == n) {
			flag = true;
			cout << fixed << setprecision(15) << 1.0 * st[i].p / st[i].q << endl;
			break;
		}
	}
	if (!flag) cout << -1 << endl;
	return 0;
}