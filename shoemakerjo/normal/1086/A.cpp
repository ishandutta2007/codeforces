#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>

int xa, ya, xb, yb, xc, yc;
vector<pii> pts;

set<pii> ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> xa >> ya >> xb >> yb >> xc >> yc;
	pts.push_back(pii(ya, xa));
	pts.push_back(pii(yb, xb));
	pts.push_back(pii(yc, xc));
	sort(pts.begin(), pts.end());

	int ymid = pts[1].first;

	pts.clear();
	pts.push_back(pii(xa, ya));
	pts.push_back(pii(xb, yb));
	pts.push_back(pii(xc, yc));
	sort(pts.begin(), pts.end());


	for (int i = pts[0].first; i <= pts[2].first; i++) {
		ans.insert(pii(i, ymid));
	}

	for (pii vp : pts) {
		int x = vp.first, y = vp.second;

		if (y < ymid) {
			for (int i = y; i <= ymid; i++) {
				ans.insert(pii(x, i));
			}
		}
		if (y > ymid) {
			for (int i = y; i >= ymid; i--) {
				ans.insert(pii(x, i));
			}
		}
	}

	cout << ans.size() << endl;
	for (pii vp : ans) {
		cout << vp.first << " " << vp.second << endl;
	}



}