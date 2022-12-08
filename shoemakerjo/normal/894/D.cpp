#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define maxn 1000010
int n, m;
int mx;
int lef[maxn+1], rig[maxn+1];
vector<vector<int>> ri, li;
vector<vector<ll>> sr, sl;


void rec(int u) {
	if (u*2 <= n) {
		rec(u*2);
		int c = u*2;
		int ad = lef[u];
		li[u].push_back(ad);
		int pt1 = 0;
		int pt2 = 0;
		while (1) {
			if (pt1 >= li[c].size()) {
				if (pt2 >= ri[c].size()) break;
				if (ad+ri[c][pt2] <= mx) li[u].push_back(ad+ri[c][pt2]);
				pt2++;
				continue;
			}
			else if (pt2 >= ri[c].size()) {
				if (ad+li[c][pt1] <= mx) li[u].push_back(ad+li[c][pt1]);
				pt1++;
				continue;
			}
			if (li[c][pt1] < ri[c][pt2]) {
				if (ad + li[c][pt1] <= mx) li[u].push_back(ad+li[c][pt1]);
				pt1++;
			}
			else {
				if (ad+ri[c][pt2] <= mx) li[u].push_back(ad+ri[c][pt2]);
				pt2++;
			}
		}
	}
	if (u*2+1 <= n) {
		rec(u*2+1);
		int c = u*2+1;
		int ad = rig[u];
		ri[u].push_back(ad);
		int pt1 = 0;
		int pt2 = 0;
		while (1) {
			if (pt1 >= li[c].size()) {
				if (pt2 >= ri[c].size()) break;
				if (ad+ri[c][pt2] <= mx) ri[u].push_back(ad+ri[c][pt2]);
				pt2++;
				continue;
			}
			else if (pt2 >= ri[c].size()) {
				if (ad+li[c][pt1] <= mx) ri[u].push_back(ad+li[c][pt1]);
				pt1++;
				continue;
			}
			if (li[c][pt1] < ri[c][pt2]) {
				if (ad + li[c][pt1] <= mx) ri[u].push_back(ad+li[c][pt1]);
				pt1++;
			}
			else {
				if (ad+ri[c][pt2] <= mx) ri[u].push_back(ad+ri[c][pt2]);
				pt2++;
			}
		}
	}
} 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	mx = 10000000;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		vector<int> b;
		ri.push_back(b);
		vector<int> b2;
		li.push_back(b2);
	}
	for (int i = 1; i <= n-1; i++) {
		int L;
		cin >> L;
		int fist = (i+1)/2;
		int sec = i+1;
		if (sec == fist*2) {
			lef[fist] = L;
		}
		else rig[fist] = L;
	}
	rec(1);

	for (int i = 0; i <= n; i++) {\
		vector<ll> b1, b2;
		sl.push_back(b1);
		sr.push_back(b2);
		// cout << "-->  " << i;

		for (int j = 0; j < li[i].size(); j++) {
			if (j == 0) {
				sl[i].push_back(li[i][j]);

			}
			else {
				sl[i].push_back(sl[i][j-1]+0LL+li[i][j]);
			}
			// cout << " " << sl[i][j];
		}
		for (int j = 0; j < ri[i].size(); j++) {
			if (j == 0) {
				sr[i].push_back(ri[i][j]);

			}
			else {
				sr[i].push_back(sr[i][j-1]+0LL+ri[i][j]);
			}
			// cout << " " << sr[i][j];
		}
		// cout << endl;
	}

	int A; int H;
	for (int i = 0; i < m; i++) {
		cin >> A >> H;
		int ch = H;
		int cval = A;
		int side = 3;
		ll ans = 0LL;
		while (cval != 0) {
			// cout << "cval  " << cval << "  " << ch << endl;
			if (ch >= 0) ans += ch+0LL;
			if (side == 3) {
				int spot = upper_bound(li[cval].begin(), li[cval].end(), ch) - li[cval].begin();
				spot--;
				// cout << "spot  " << spot << endl;
				if (spot >= 0) {
					ans += (spot+1LL)*ch;
					ans -= sl[cval][spot]+0LL;
				}
				spot = upper_bound(ri[cval].begin(), ri[cval].end(), ch) - ri[cval].begin();
				spot--;
				if (spot >= 0) {
					ans += (spot+1LL)*ch;
					ans -= sr[cval][spot]+0LL;
				}
			}
			if (side == 1) { //get the left
				int spot = upper_bound(li[cval].begin(), li[cval].end(), ch) - li[cval].begin();
				spot--;
				// cout << "  HERE " << spot << endl;
				if (spot >= 0) {
					ans += (spot+1LL)*ch;
					ans -= sl[cval][spot]+0LL;
				}
			}
			if (side == 2) {
				int spot = upper_bound(ri[cval].begin(), ri[cval].end(), ch) - ri[cval].begin();
				spot--;
				if (spot >= 0) {
					ans += (spot+1LL)*ch;
					ans -= sr[cval][spot]+0LL;
				}
			}
			int nx = cval/2;
			if (nx*2 == cval) {
				ch -= lef[nx];
				side = 2;
			}
			else {
				ch -= rig[nx];
				side = 1;
			}
			cval = nx;
			// cout << " : " << ans << endl;
		}
		cout << ans << '\n';
	}
	cin >> A;
}