#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;
int n, q;

#define pii pair<int, int>
map<int, int> res;
int nums[maxn];

bool gre[maxn];
int xi[maxn];
int BIT[maxn];

int ndone = 0;

void update(int u) {
	// cout << u << " updating" << endl;
	ndone++;
	while (u <= 100000) {
		BIT[u]++;
		u += u & (-u);
	}
}

int query(int u) {

	u--;
	int res = 0;
	while (u > 0) {
		res += BIT[u];
		u -= u & (-u);
	}
	return ndone - res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	string c;
	for (int i = 1; i <= q; i++) {
		cin >> c >> xi[i];
		if (c == ">") gre[i] = true;
		else gre[i] = false;
	}

	set<pii> vals;
	for (int i = -100000; i <= 100000; i++) {
		vals.insert(pii(abs(i), i));
	}
	for (int i = q; i >= 1; i--) {

		// cout << "on: " << i << endl;
		if (gre[i]) {
			//greater than a positive
			if (xi[i] >= 0) {
				pii vp = pii(xi[i], maxn);

				auto it = vals.upper_bound(vp);
				while (it != vals.end()) {
					int cabs = it->first;
					int cval = it->second;

					int flips = query(cabs);
					if (flips % 2 == 0) {
						res[cval] = 0-cabs; //end up negative
					}
					else res[cval] = cabs;

					it = vals.erase(it);
				}
			}
			else {
				//greater than a negative
				pii vp = pii(0-xi[i]-1, maxn);

				auto it = vals.upper_bound(vp);
				while (it != vals.end()) {
					int cabs = it->first;
					int cval = it->second;

					int flips = query(cabs);
					if (flips % 2 == 0) {
						res[cval] = 0-cabs; //end up negative
					}
					else res[cval] = cabs;

					it = vals.erase(it);
				}

				update(0-xi[i]);
			}

		}
		else {
			//less than a negative
			if (xi[i] <= 0) {
				// cout << " this " << endl;
				pii vp = pii(0-xi[i], maxn);

				auto it = vals.upper_bound(vp);
				// cout << " at this" << endl;
				while (it != vals.end()) {
					int cabs = it->first;
					int cval = it->second;

					int flips = query(cabs);
					if (flips % 2 == 0) {
						res[cval] = cabs; //end up negative
					}
					else res[cval] = 0-cabs;

					it = vals.erase(it);
				}
				// cout << " at bot " << endl;
			}
			else {
				// cout << "  here" << endl;
				//less than a positive
				pii vp = pii(xi[i]-1, maxn);

				auto it = vals.upper_bound(vp);
				while (it != vals.end()) {
					int cabs = it->first;
					int cval = it->second;

					// cout << cabs << " -- " << cval << endl;

					int flips = query(cabs);
					if (flips % 2 == 0) {
						res[cval] = cabs; //end up negative
					}
					else res[cval] = 0-cabs;

					it = vals.erase(it);
				}
				update(xi[i]);
			}
			// cout << " got here " << endl;

			// cout << " down here " << endl;
		}
	}


	//output answer using the map
	for (pii vp : vals) {
		int cabs = vp.first;
		int cval = vp.second;

		if (query(cabs)%2 == 0) {
			res[cval] = cval;
		}
		else res[cval] = 0-cval;
	}

	for (int i = 1; i <= n; i++) {
		cout << res[nums[i]] << " ";
	}
	cout << endl;

}