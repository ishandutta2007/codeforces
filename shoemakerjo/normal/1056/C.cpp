#include <bits/stdc++.h>

using namespace std;

#define maxn 1010
#define pii pair<int, int>

int n, m;
int nums[2*maxn];

int a[maxn];
int b[maxn];

int mymatch[2*maxn];

set<pii> vals;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= 2*n;  i++) {
		cin >> nums[i];
		vals.insert(pii(nums[i], i));
	}

	for (int i = 0; i < m; i++) {
		cin >> a[i];
		cin >> b[i];
		mymatch[a[i]] = b[i];
		mymatch[b[i]] = a[i];
	}


	// cout << "here" << endl;
	int t;
	cin >> t;

	//I have the first or the second turn
	//if I am first

	int x;

	if (t == 2) {
			for (int i = 1; i <= n; i++) {
				cin >> x;
				vals.erase(vals.find(pii(nums[x], x)));

				bool done = false;
				if (mymatch[x] != 0) {
					int ot = mymatch[x];

					if (vals.find(pii(nums[ot], ot)) != vals.end()) {
						vals.erase(vals.find(pii(nums[ot], ot)));
						cout << ot << endl;
						done = true;
					}
					
				}
				if (!done) {

					for (int j = 0; j < m; j++) {
						if (vals.find(pii(nums[a[j]], a[j])) != vals.end()) {
							if (nums[a[j]] >= nums[b[j]]) {
								vals.erase(vals.find(pii(nums[a[j]], a[j])));
								cout << a[j] << endl;
								done = true;
								break;
							}
							else {
								vals.erase(vals.find(pii(nums[b[j]], b[j])));
								cout << b[j] << endl;
								done = true;
								break;
							}
						}
					}
					if (!done) {
						pii cur = *(vals.rbegin());

						cout << cur.second << endl;
						vals.erase(vals.find(cur));
					}
				}
				cout.flush();				
			}
	}
	else {
		for (int i = 1; i <= n; i++) {
			bool done = false;
			for (int j = 0; j < m; j++) {
				if (vals.find(pii(nums[a[j]], a[j])) != vals.end()) {
					if (nums[a[j]] >= nums[b[j]]) {
						vals.erase(vals.find(pii(nums[a[j]], a[j])));
						cout << a[j] << endl;
						done = true;
						break;
					}
					else {
						vals.erase(vals.find(pii(nums[b[j]], b[j])));
						cout << b[j] << endl;
						done = true;
						break;
					}
				}
			}
			if (!done) {
				pii cur = *(vals.rbegin());
				cout << cur.second << endl;
				vals.erase(vals.find(cur));
			}
			cout.flush();

			cin >> x;
			vals.erase(vals.find(pii(nums[x], x)));

		}
	}

}