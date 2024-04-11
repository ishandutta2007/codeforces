#include <string>
#include <iostream>
using namespace std;
int Q, cnt[262155]; string tp, s;
int main() {
	ios::sync_with_stdio(false);
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> tp >> s;
		s = string(18 - s.size(), '0') + s;
		int bit = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] % 2) bit |= 1 << j;
		}
		if (tp == "+") cnt[bit]++;
		if (tp == "-") cnt[bit]--;
		if (tp == "?") cout << cnt[bit] << endl;
	}
	return 0;
}