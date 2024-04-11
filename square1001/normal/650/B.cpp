#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a, b, t, sl[500009], sr[500009]; string s;
int main() {
	cin >> n >> a >> b >> t >> s;
	for (int i = 1; i < n; i++) {
		sl[i] = sl[i - 1] + a + 1;
		sr[i] = sr[i - 1] + a + 1;
		if (s[i] == 'w') sl[i] += b;
		if (s[s.size() - i] == 'w') sr[i] += b;
	}
	if (s[0] == 'w') t -= b; t--;
	int ret = (t >= 0 ? 1 : 0);
	for (int i = 1; i < n; i++) {
		if (sl[i] <= t) ret = max(ret, i + 1);
		if (sr[i] <= t) ret = max(ret, i + 1);
	}
	for (int i = 1; i < n; i++) {
		int ptr = lower_bound(sr, sr + n, t - sl[i] - i * a + 1) - sr - 1;
		if (ptr >= 1) ret = max(ret, ptr + i + 1);
	}
	for (int i = 1; i < n; i++) {
		int ptr = lower_bound(sl, sl + n, t - sr[i] - i * a + 1) - sl - 1;
		if (ptr >= 1) ret = max(ret, ptr + i + 1);
	}
	printf("%d\n", min(ret, n));
	return 0;
}