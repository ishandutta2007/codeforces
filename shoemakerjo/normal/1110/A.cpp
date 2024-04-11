#include <bits/stdc++.h>

using namespace std;

int nums[100010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int b, k;
	cin >> b >> k;
	int od = 0;

	int cur;
	for (int i = 0; i < k; i++) {
		cin >> nums[i];
	}
	int bs = 1;
	for (int i = k-1; i >= 0; i--) {
		cur = nums[i];
		od = (od + bs* cur % 2) % 2;
		bs = bs*b%2;
	}
	if (od == 0) cout << "even" << endl;
	else cout << "odd" << endl;
}