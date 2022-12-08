#include <bits/stdc++.h>

using namespace std;

map<int, int> ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	int cur;
	while (q--) {
		cin >> cur;
		int tp = 1;
		while (tp <= cur) tp *= 2;
		if (cur == tp - 1) {
			if (ans.count(cur)) {
				cout << ans[cur] << endl;
			}
			else {
				for (int i = cur-1; i >= 1; i--) {
					if (cur % i == 0) {
						ans[cur] = i;
						cout << i << endl;
						break;
					}
				}
			}
		}
		else {
			cout << tp-1 << endl;
		}
	}
}