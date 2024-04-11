#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector <int> cnt(110);
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			cnt[x]++;
		}
		int pos = 0;
		while (cnt[pos]) cnt[pos]--, cout << pos << " ", pos++;
		for (int i = 0; i < cnt.size(); i++) {
			while (cnt[i]--) cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}