#include <bits/stdc++.h>

using namespace std;

#define pii pair<double, double>

#define maxn 200010


//problem is almost all in doubles
// vector<pii> 
// int qx[maxn];
// int qy[maxn];
int n, q;
double prefsize[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double sy, a, b;
	cin  >> sy >> a >> b;
	cin >> n;
	double l, r;
	vector<pii> ver;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		ver.push_back(pii(l, r));
	}
	sort(ver.begin(), ver.end());
	for (int i = 0; i < ver.size(); i++) {
		if (i != 0) prefsize[i] = prefsize[i-1];
		else prefsize[i] = 0;
		prefsize[i] += ver[i].second-ver[i].first;
	}
	cin >> q;
	int x, y;
	cout << fixed << setprecision(7);
	for (int i = 0; i < q; i++) {
		cin >> x >> y;
		// qx[i] = x;
		// qy[i] = y;
		double slope = (y-sy)/(x-a);
		double fc = (slope*x - y)/slope;
		slope = (y-sy)/(x-b);
		double sc = (slope*x - y)/slope;

		if (x == a) fc = a;
		if (x == b) sc = b;

		// cout << "fc: " << fc << endl;
		// cout << "sc: " << sc << endl;
		double tdist = sc-fc;

		int indo = upper_bound(ver.begin(), ver.end(), pii(fc, 0.0)) - ver.begin();
		--indo;
		double fsize = 0.0, ssize = 0.0;
		if (indo >= 0) {
			fsize = prefsize[indo];
			if (ver[indo].second > fc) {
				fsize -= ver[indo].second - fc;
			}
		}

		indo = upper_bound(ver.begin(), ver.end(), pii(sc, 0.0)) - ver.begin();
		--indo;
		if (indo >= 0) {
			ssize = prefsize[indo];
			if (ver[indo].second > sc) {
				ssize -= ver[indo].second - sc;
			}
		}
		// cout << "fsize: " << fsize << endl;
		// cout << "ssize: " << ssize << endl;
		double div = ssize - fsize;
		div /= tdist;

		cout << div*(b-a) << '\n';


	}
	cout.flush();
}