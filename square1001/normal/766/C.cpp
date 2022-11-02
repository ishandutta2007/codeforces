#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 1000000007;
const int inf = 1012345678;
int n, c[26], dp1[1009], dp2[1009], dp3[1009]; string s; bool f[26];
int main() {
	cin >> n >> s;
	for (int i = 0; i < 26; i++) cin >> c[i];
	dp1[0] = 1;
	for (int i = 0; i < n; i++) {
		dp3[i + 1] = inf;
		fill(f, f + 26, false);
		for (int j = i; j >= 0; j--) {
			f[s[j] - 97] = true;
			int l = i - j + 1;
			bool flag = true;
			for (int k = 0; k < 26; k++) {
				if (f[k] && l > c[k]) flag = false;
			}
			if (!flag) break;
			dp1[i + 1] += dp1[j];
			dp2[i + 1] = max({ dp2[i + 1], dp2[j], l });
			dp3[i + 1] = min(dp3[i + 1], dp3[j] + 1);
			if (dp1[i + 1] >= mod) dp1[i + 1] -= mod;
		}
	}
	cout << dp1[n] << endl;
	cout << dp2[n] << endl;
	cout << dp3[n] << endl;
	return 0;
}