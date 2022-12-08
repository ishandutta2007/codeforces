#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
#define pii pair<int, int>

const int maxn = 100010;
// int n;

bool isinside(pii O, pii A, pii B) {
	//is A inside the arc from O to B?
	// return 1LL*(A.first-  O.first)*(B.second - O.second) - 
	// 	1LL*(A.second - O.second)*(B.first - O.first);

	if (O.first == B.first) return false;

	ld b = (O.second - B.second + B.first*1LL*B.first - O.first*1LL*O.first);
	b /= (O.first - B.first);

	ld c = O.second - O.first*1.0*O.first;
	c -= O.first * b;

	return (A.first*1.0*A.first + b * A.first + c < A.second);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<pii> opoints;
	int N;
	int k = 0; //last index (not needed)
	cin >> N;
	int x, y;
	for (int i = 0; i < N; i++) { //scan in points
		cin >> x >> y;
		opoints.push_back(pii(x, y));
	}
	sort(opoints.begin(), opoints.end());
	vector<pii> hull;

	for (int i = N-1; i >= 0; i--) {
		while (k >= 2 && isinside(hull[k-2], hull[k-1], opoints[i]) == false) {
			k--;
			hull.pop_back();
		}
		k++;
		hull.push_back(opoints[i]);
	}

	//remove duplicate x coordinates

	int res = hull.size()-1;

	set<int> seen;
	for (pii vp : hull) {
		if (seen.count(vp.first)) {
			res--;
		}
		seen.insert(vp.first);
	}

	cout << res << endl;
}