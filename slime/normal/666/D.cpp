#include <bits/stdc++.h>
#define ll long long
#define maxn 5005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int ans = 2e9;
int inf = 1e9;
int x[4][2];
int y[4][2];
int ed[4][2];
void work() {
	int b[4] = {0, 0, 0, 0};
	for (b[0] = 0; b[0] < 4; b[0]++)
		for (b[1] = 0; b[1] < 4; b[1]++)
			for(b[2] = 0; b[2] < 4; b[2]++)
				for (b[3] = 0; b[3] < 4; b[3]++) {
					int fl = 1;
					for (int i = 0; i < 4; i++)
						for (int j = i + 1; j < 4; j++)
							if (b[i] == b[j]) fl = 0;
					if (!fl) continue;
				//	for (int i = 0; i < 4; i++) cout << b[i] << ' ';
				//	cout << endl;
					int nans = 0;
					for (int i = 0; i < 4; i++) {
						int ur = abs(x[i][0] - y[b[i]][0]), uj = abs(x[i][1] - y[b[i]][1]);
						if (ur != 0 && uj != 0) nans = inf;
						else nans = max(nans, ur + uj);
					}
					if (nans < ans) {
						ans = nans;
					//	cout << "!!" << nans << endl;
						for (int i = 0; i < 4; i++)
							ed[i][0] = y[b[i]][0], 
							ed[i][1] = y[b[i]][1];
					}
				}
	//for (int i = 0; i < 4; i++) cout << y[i][0] << ' ' << y[i][1] << endl; 
	//while (1);
}
void dd(vi x, vi s) {
	if (abs(x[1] - x[0]) != abs(s[1] - s[0])) return ;
	if (x[1] == x[0]) return ;
	//cout << x[0] << ' ' << x[1] << ' ' << s[0] << ' ' << s[1] << endl;
	for (int i = 0; i < 4; i++) {
		y[i][0] = x[i & 1];
		if (i & 2) y[i][1] = s[1];
		else y[i][1] = s[0];
	}
	work();
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < 4; j++)
			cin >> x[j][0] >> x[j][1];
		ans = 2 * inf;
		for (int j = 0; j < 16; j++) {
			vi r[2];
			for (int k = 0; k < 4; k++)
				if (j & (1 << k)) r[0].pb(x[k][0]);
				else r[1].pb(x[k][1]);
			for (int i = 0; i < 2; i++) {
				vi cur;
				sort(r[i].begin(), r[i].end());
				for (int j = 0; j < r[i].size(); j++)
					if (j == 0 || r[i][j] != r[i][j - 1]) cur.pb(r[i][j]);
				r[i] = cur;
			}
			if (r[0].size() > 2 || r[1].size() > 2) continue;
			else if (r[0].size() < 2 && r[1].size() < 2) continue;
			else {
				int pl = 0;
				if (r[1].size() == 2) pl = 1;
				int d = r[pl][1] - r[pl][0];
				if (r[pl ^ 1].size() == 2) dd(r[0], r[1]);
				else if (r[pl ^ 1].size() == 1) {
					r[pl ^ 1].resize(2);
					r[pl ^ 1][1] = r[pl ^ 1][0] + d, dd(r[0], r[1]);
					r[pl ^ 1][1] = r[pl ^ 1][0] - d, dd(r[0], r[1]);
				} 
				else {
					r[pl ^ 1].resize(2);
					for (int j = 0; j < 4; j++) {
						r[pl ^ 1][0] = x[j][pl ^ 1];
						r[pl ^ 1][1] = r[pl ^ 1][0] + d, dd(r[0], r[1]);
						r[pl ^ 1][1] = r[pl ^ 1][0] - d, dd(r[0], r[1]);
					}
					for (int j = 0; j < 4; j++)
						for (int k = j; k < 4; k++) {
							for (int cnt = -3; cnt <= 3; cnt++) {
								r[pl ^ 1][0] = (x[j][pl ^ 1] + x[k][pl ^ 1] + d) / 2 + cnt;
								r[pl ^ 1][1] = r[pl ^ 1][0] + d, dd(r[0], r[1]);
								r[pl ^ 1][1] = r[pl ^ 1][0] - d, dd(r[0], r[1]);
								
								r[pl ^ 1][0] = (x[j][pl ^ 1] + x[k][pl ^ 1]) / 2 + cnt;
								r[pl ^ 1][1] = r[pl ^ 1][0] + d, dd(r[0], r[1]);
								r[pl ^ 1][1] = r[pl ^ 1][0] - d, dd(r[0], r[1]);
							}
						}
				}
			}
		}
		if (ans >= inf) cout << -1 << endl;
		else {
			cout << ans << endl;
			for (int j = 0; j < 4; j++)
				cout << ed[j][0] << ' ' << ed[j][1] << endl;
			}
	}
	return 0;
}