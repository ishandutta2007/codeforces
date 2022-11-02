#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int Q;
	cin >> Q;
	while (Q--) {
		string S;
		cin >> S;
		int ans = 0, pre = 0;
		for (int i = 0; i < S.size(); ++i) {
			if (S[i] == 'R') {
				ans = max(ans, i + 1 - pre);
				pre = i + 1;
			}
		}
		ans = max(ans, int(S.size()) + 1 - pre);
		cout << ans << '\n';
	}
	return 0;
}