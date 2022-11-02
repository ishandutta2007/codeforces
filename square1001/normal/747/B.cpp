#include <string>
#include <iostream>
using namespace std;
int n, cnt[4]; string s;
int main() {
	cin >> n >> s;
	if (n % 4 != 0) cout << "===" << endl;
	else {
		for (int i = 0; i < n; i++) {
			if (s[i] == 'A') cnt[0]++;
			if (s[i] == 'G') cnt[1]++;
			if (s[i] == 'C') cnt[2]++;
			if (s[i] == 'T') cnt[3]++;
		}
		if (cnt[0] > n / 4 || cnt[1] > n / 4 || cnt[2] > n / 4 || cnt[3] > n / 4) cout << "===" << endl;
		else {
			for (int i = 0; i < n; i++) {
				if (s[i] == '?') {
					if (cnt[0] < n / 4) s[i] = 'A', cnt[0]++;
					else if (cnt[1] < n / 4) s[i] = 'G', cnt[1]++;
					else if (cnt[2] < n / 4) s[i] = 'C', cnt[2]++;
					else if (cnt[3] < n / 4) s[i] = 'T', cnt[3]++;
				}
			}
			cout << s << endl;
		}
	}
	return 0;
}