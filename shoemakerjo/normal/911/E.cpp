#include <bits/stdc++.h>

using namespace std;
#define maxn 200010
bool seg[maxn*4];

int n;

void up(int us, int ue, int ss, int se, int si) {
	if (seg[si]) {
		if (ss != se) {
			seg[si*2+1] = true;
			seg[si*2+2] = true;
		}
	}
	if (us > ue || ss > se || us > se || ue < ss) return;
	if (us <= ss && se <= ue) {
		seg[si] = true;
		if (ss != se) {
			seg[si*2+1] = true;
			seg[si*2+2] = true;
		}
		return;
	}
	int mid = (ss+se)/2;
	up(us, ue, ss, mid, si*2+1);
	up(us, ue, mid+1, se, si*2+2);
}

void update(int low, int high) {
	up(low, high, 1, n, 0);
}

bool qu(int spot, int ss, int se, int si) {
	if (ss > se || spot < ss || spot > se) return false;
	if (seg[si]) {
		if (ss != se) {
			seg[si*2+1] = true;
			seg[si*2+2] = true;
		}
	}
	if (spot == ss && spot == se) {
		return seg[si];
	}
	int mid = (ss+se)/2;
	if (spot <= mid) {
		return qu(spot, ss, mid, si*2+1);
	}
	return qu(spot, mid+1, se, si*2+2);
}

bool query(int u) {
	return qu(u, 1, n, 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> n >> k;
	int nums[n+1];
	bool take[n+1];
	for (int i = 0; i <= n; i++) {
		take[i] = false;
	}
	for (int i = 0; i < k; i++) {
		cin >> nums[i];
		take[nums[i]] = true;
	}
	vector<int> cur;
	int spot = k;
	for (int i = 1; i <= n; i++) {
		if (!take[i]) {
			if (i > 1 && !take[i-1]) cur.push_back(i);
			else {
				for (int j = cur.size()-1; j >= 0; j--) {
					nums[spot] = cur[j];
					spot++;
				}
				cur.clear();
				cur.push_back(i);
			}
		}
	}
	if (cur.size() > 0) {
		for (int j = cur.size()-1; j >= 0; j--) {
			nums[spot] = cur[j];
			spot++;
		}
	}

	int cmin = n*2;
	bool bad = false;
	for (int i = 0; i < maxn*4; i++) {
		seg[i] = false;
	}
	for (int i = n-1; i >= 0; i--) {
		// cout << "i   " << i << endl;
		if (query(nums[i])) {
			bad = true;
		}
		// cout << "here" << endl;
		if (nums[i] > cmin) {
			// cout << cmin << "   -    " << nums[i] << endl;
			update(cmin, nums[i]);
		}
		else {
			cmin = nums[i];
		}
		// cout << "here" << endl;
	}
	if (bad) cout << -1 << endl;
	else {
		for (int i = 0; i < n; i++) {
			cout << nums[i] << " ";
		}
		cout << endl;
	}
	cin >> k;
}