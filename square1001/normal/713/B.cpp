#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const bool debug = false;
int ask(int xa, int ya, int xb, int yb) {
	cout << "? " << xa + 1 << ' ' << ya + 1 << ' ' << xb << ' ' << yb << endl;
	int res = 0;
	if (!debug) {
		cin >> res;
	}
	else {
		if (xa <= 1 && 4 <= xb && ya <= 1 && 2 <= yb) ++res;
		if (xa <= 2 && 5 <= xb && ya <= 3 && 5 <= yb) ++res;
	}
	return res;
}
int main() {
	int N;
	cin >> N;
	vector<int> cx, cy;
	for (int i = 0; i < 2; ++i) {
		int l, r;
		l = 0, r = N;
		while (r - l > 1) {
			int m = (l + r) >> 1;
			int res = ask(0, 0, m, N);
			if (res <= i) l = m;
			else r = m;
		}
		cx.push_back(r);
		l = 0, r = N;
		while (r - l > 1) {
			int m = (l + r) >> 1;
			int res = ask(m, 0, N, N);
			if (res <= i) r = m;
			else l = m;
		}
		cx.push_back(l);
		l = 0, r = N;
		while (r - l > 1) {
			int m = (l + r) >> 1;
			int res = ask(0, 0, N, m);
			if (res <= i) l = m;
			else r = m;
		}
		cy.push_back(r);
		l = 0, r = N;
		while (r - l > 1) {
			int m = (l + r) >> 1;
			int res = ask(0, m, N, N);
			if (res <= i) r = m;
			else l = m;
		}
		cy.push_back(l);
	}
	sort(cx.begin(), cx.end());
	cx.erase(unique(cx.begin(), cx.end()), cx.end());
	sort(cy.begin(), cy.end());
	cy.erase(unique(cy.begin(), cy.end()), cy.end());
	vector<int> xa, ya, xb, yb;
	for (int i = 0; i < cx.size(); ++i) {
		for (int j = i + 1; j < cx.size(); ++j) {
			for (int k = 0; k < cy.size(); ++k) {
				for (int l = k + 1; l < cy.size(); ++l) {
					int res = ask(cx[i], cy[k], cx[j], cy[l]);
					if (res == 1) {
						xa.push_back(cx[i]);
						ya.push_back(cy[k]);
						xb.push_back(cx[j]);
						yb.push_back(cy[l]);
					}
				}
			}
		}
	}
	vector<int> txa, tya, txb, tyb;
	for (int i = 0; i < xa.size(); ++i) {
		bool flag = true;
		for (int j = 0; j < xa.size(); ++j) {
			if (i == j) continue;
			if (xa[i] <= xa[j] && xb[j] <= xb[i] && ya[i] <= ya[j] && yb[j] <= yb[i]) {
				flag = false;
			}
		}
		if (flag) {
			txa.push_back(xa[i]);
			tya.push_back(ya[i]);
			txb.push_back(xb[i]);
			tyb.push_back(yb[i]);
		}
	}
	xa = txa;
	ya = tya;
	xb = txb;
	yb = tyb;
	cout << "! " << xa[0] + 1 << ' ' << ya[0] + 1 << ' ' << xb[0] << ' ' << yb[0] << ' ' << xa[1] + 1 << ' ' << ya[1] + 1 << ' ' << xb[1] << ' ' << yb[1] << endl;
	return 0;
}