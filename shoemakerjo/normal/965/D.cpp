#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int w, l;
	cin >> w >> l;
	int nums[w+1];
	nums[w] = 0;
	int cval[w+1]; //number that got here
	fill(cval, cval+w+1, 0);
	set<int> hasleft;
	hasleft.insert(w);
	hasleft.insert(w*2 + l*2); //infinity value
	for (int i = 1; i < w; i++) {
		cin >> nums[i];
		hasleft.insert(i);
	}
	int ans = 0;
	for (int i = 1; i < w; i++) {
		// cout << "i: " << i << endl;
		if (i <= l) {
			//can get here from zero
			cval[i] = nums[i]; //completely fill this
		}
		if (hasleft.find(i) != hasleft.end()) {
			hasleft.erase(i);
		}
		auto it = hasleft.upper_bound(i+l); 
		--it;
		if (*it == w) {
			ans += cval[i];
			continue;
		}
		// cout << "pre loop" << endl;
		while (true) {

			int cur = *it;
			int gap = nums[cur] - cval[cur];
			if (gap <= cval[i]) {
				cval[cur] = nums[cur];
				cval[i] -= gap;
				if (it == hasleft.begin()) {
					hasleft.erase(it);
					break;
				}
				it = hasleft.erase(it);
				--it;
			}
			else {
				cval[cur] += cval[i];
				break;
			}
		}
		// cout << "post loop" << endl;
	}
	cout << ans << endl;
	cin >> w;

}