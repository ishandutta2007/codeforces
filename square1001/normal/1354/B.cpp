#include <map>
#include <set>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
const int inf = 1012345678;
int main() {
	int Q;
	cin >> Q;
	while (Q--) {
		string S;
		cin >> S;
		vector<int> cnt(3);
		int pre = 0, ans = inf;
		for (int i = 0; i < S.size(); ++i) {
			while (pre != S.size() && (cnt[0] == 0 || cnt[1] == 0 || cnt[2] == 0)) {
				++cnt[S[pre++] - '1'];
			}
			if (cnt[0] != 0 && cnt[1] != 0 && cnt[2] != 0) {
				ans = min(ans, pre - i);
			}
			--cnt[S[i] - '1'];
		}
		cout << (ans == inf ? 0 : ans) << '\n';
	}
	return 0;
}