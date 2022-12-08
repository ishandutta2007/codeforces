#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
#define maxn 100001

int nums[maxn];
int k;

void merge(int l, int r) {
	bool unsort = false;
	int mid = (l+r)/2;
	if (l == r-1) return;
	if (k > 0) {
		k-=2;
		unsort = true;
	}
	merge(l, mid);
	merge(mid, r);
	if (unsort) {
		int bspot = l, sspot = mid;
		for (int i = l; i < mid; i++) {
			if (nums[i] > nums[bspot]) {
				bspot = i;
			}
		}
		for (int i = mid; i < r; i++) {
			if (nums[i] < nums[sspot]) {
				sspot = i;
			}
		}
		int temp = nums[bspot];
		nums[bspot] = nums[sspot];
		nums[sspot] = temp;
	}
}

int main() {
	int n;
	cin >> n >> k;
	if (k%2 == 0) {
		cout << -1 << endl;
		return 0;
	}
	k--;
	for (int i = 1; i <= n; i++) {
		nums[i] = i;
	}
	merge(1, n+1);

	if (k > 0) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (i > 1) cout << " ";
		cout << nums[i];
	}
	cout << endl;
	// cin >> n;
}