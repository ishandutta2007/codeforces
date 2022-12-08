#include <bits/stdc++.h>
#define maxn 65
using namespace std;
double prob[65][65];
double expec[65][65];
double adv[65][7];

double ran(int start, int end) {
	// cout << start << " " << end << endl;
	if (expec[start][end] != -1) return expec[start][end];
	if (start == end) {
		expec[start][end] = 0.0;
		return 0.0;
	}
	else {
		int len = end-start + 1;
		int wins = 0;
		int pts = 1;
		while (len%2 == 0) {
			len/=2;
			wins++;
			pts*=2;
		}
		pts-=1;
		expec[start][end] = 0.0;
		for (int i = start; i <= end; i++) {
			double cur = 0.0;
			int cpt = 1;
			for (int j = 1; j <= wins; j++) {
				cur += adv[i][j]*cpt;
				cpt*=2;
			}
			// cur = adv[i][wins]*pts;
			// cout << start << " " << end << " " << cur << " " << i << endl;
			int point = start;
			while (point < i) {
				int cend = point;
				if (point + 1-1 < i) cend = point+1-1;
				int powe = 1;
				for (int j = 2; j <= 7; j++) {
					powe*=2;
					if (point + powe-1 < i) cend = point + powe-1;
				}
				cur += ran(point, cend);
				// cout << "  " << start << " " << end << " - " <<i << 
				// "  -  " <<  point << " " << cend << endl;
				point = cend+1;
			}
			point = end;
			while (point > i) {
				int cend = point;
				if (point - 1+1 > i) cend = point-1+1;
				int powe = 1;
				for (int j = 2; j <= 7; j++) {
					powe*=2;
					if (point - powe+1 > i) cend = point - powe+1;
				}
				cur += ran(cend, point);
				// cout << "  " << start << " " << end << " - " <<i << 
				// "  -  " <<  cend << " " << point << endl;
				point = cend-1;
			}
			// cout << start << " " << end << " " << cur << " " << i << endl;
			expec[start][end] = max(expec[start][end], cur);
		}
		// cout << start << "   -   " << end << " " << expec[start][end] << endl;
		return expec[start][end];
	}
}


int main() {
	int N;
	cin >> N;
	int teams = 1;
	for (int i = 1; i <= N; i++) {
		teams*=2;
	}
	for (int i = 0; i < teams; i++) {
		for (int j = 0; j < teams; j++) {
			cin >> prob[i][j];
			prob[i][j]/=100.0;
		}
	}
	for (int i = 0; i < teams; i++) {
		for (int j = 0; j < teams; j++) {
			expec[i][j] = -1;
		}

	}
	for (int i = 0; i < teams; i++) {
		adv[i][0] = 1.0;
	}
	int cpow = 1;
	// cout << fixed << setprecision(3);
	for (int k = 1; k <= N; k++) {
		cpow*=2;
		for (int i = 0; i < teams; i++) {
			adv[i][k] = 0.0;
			int sp = (i/cpow)*cpow;
			if (i <= sp-1+cpow/2) sp+=cpow/2;

			for (int j = sp; j < sp+cpow/2; j++) {
				if (i == j) continue;
				adv[i][k] += prob[i][j] * adv[i][k-1]*adv[j][k-1];
			}
			// cout << i << " - " << k << " " << adv[i][k] <<  "   " << sp << endl;
		}
	}
	cout << fixed << setprecision(15);
	cout << ran(0, teams-1) << endl;
	// cin >> N;
}