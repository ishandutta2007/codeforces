#include <bits/stdc++.h>

#define ti tuple<int, int, int>
using namespace std;

#define maxn 300010
#define ll long long




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	char type[n];
	ll p[n];
	ll ans = 0LL;
	
	for (int i = 0; i < n; i++) {
		cin >> p[i] >> type[i];
		if (i > 0) {
			if (type[i] == 'G') {
				int spot = -1;
				vector<ll> rs;
				vector<ll> bs;
				for (int j = i-1; j >= 0; j--) {
					if (type[j] == 'G') {
						spot = j;
						break;
					}
					if (type[j] == 'R') {
						rs.push_back(p[j]);
					}
					if (type[j] == 'B') {
						bs.push_back(p[j]);
					}
				}
				// cout << "here " << spot <<   "   --   " << i << endl;
				if (spot == -1) {
					ans += 2LL*p[i];
					if (rs.size() == 0) {
						ans -= p[i];
					}
					else {
						ans -= rs[rs.size()-1];
					}
					if (bs.size() == 0) {
						ans -= p[i];
					}
					else {
						ans -= bs[bs.size()-1];
					}
				}
				else {
					ll rm = 0, bm = 0;
					if (rs.size() > 0) {
						reverse(rs.begin(), rs.end());
						rm = max(rm, rs[0]-p[spot]);
						rm = max(rm, p[i]-rs[rs.size()-1]);
						for (int k = 1; k < rs.size(); k++) {
							rm = max(rm, rs[k]-rs[k-1]);
						}
					}
					if (bs.size() > 0) {
						reverse(bs.begin(), bs.end());
						bm = max(bm, bs[0]-p[spot]);
						bm = max(bm, p[i]-bs[bs.size()-1]);
						for (int k = 1; k < bs.size(); k++) {
							bm = max(bm, bs[k]-bs[k-1]);
						}
					}
					

					if (rs.size() == 0 && bs.size() == 0) {
						ans += p[i]-p[spot];
					}
					else if (rs.size() == 0) {
						ll addon = 2*(p[i]-p[spot]);
						addon -= bm;
						ans += addon;
					}
					else if (bs.size() == 0) {
						ll addon = 2*(p[i]-p[spot]);
						addon -= rm;
						ans += addon;
					}
					else {
						
						ll o1 = 2*(p[i]-p[spot]);
						ll o2 = 3*(p[i]-p[spot]);

						if (rs.size() != 0) 
							o2 -= rm;
						if (bs.size() != 0) 
							o2 -= bm;
						ans += min(o1, o2);
					}
				}
				

			}
		}


	}
	int rspot = -1, bspot = -1, gspot = -1;
	for (int i = n-1; i >= 0; i--) {
		if (type[i] == 'R' && rspot == -1) {
			rspot = i;
		}
		if (type[i] == 'B' && bspot == -1) {
			bspot = i;
		}
		if (type[i] == 'G') {
			gspot = i;
			break;
		}
	}
	if (gspot == -1) {
		vector<int> rs, bs;
		for (int i = 0; i < n; i++) {
			if (type[i] == 'R') {
				rs.push_back(i);
			}
			if (type[i] == 'B') {
				bs.push_back(i);
			}
		}
		if (rs.size() > 0) {
			ans += p[rs[rs.size()-1]]-p[rs[0]];
		}
		if (bs.size() > 0) {
			ans += p[bs[bs.size()-1]]-p[bs[0]];
		}
	}
	else {
		if (rspot != -1) {
			ans += p[rspot]-p[gspot];
			}
		if (bspot != -1) {
			ans += p[bspot]-p[gspot];
		}
	}
	cout << ans << endl;
	cin >> ans;
	

}