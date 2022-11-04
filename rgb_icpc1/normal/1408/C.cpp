#include <bits/stdc++.h>

using namespace std;
#define MN 100005

int n;
double l, a[MN];

int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	int Tc;
	for (cin >> Tc; Tc--; ) {
		cin >> n >> l;
		for (int i = 1; i <= n; i++) cin >> a[i];
		int pa = 1, pb = n;
		double rlt = 0, sa = 1, sb = 1, posa = 0, posb = l;
		while (pa <= pb) {
			double ta = (a[pa] - posa) / sa;
			double tb = (posb - a[pb]) / sb;
			double t = min(ta, tb);
			posa += sa * t;
			posb -= sb * t;
			rlt += t;
			if (ta < tb) sa = sa + 1, pa++;
			else sb = sb + 1, pb--;
		}
		cout << fixed << setprecision(10) << rlt + (posb - posa) / (sa + sb) << endl;
	}
	
	return 0;

}