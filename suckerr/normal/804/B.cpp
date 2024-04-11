#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
const int MOD = 1e9 + 7;

char s[N];
int ans = 0;

int main() {
	scanf("%s", s);
	int cnt = 0;
	for (int i = strlen(s) - 1; i >= 0; i--) {
		if (s[i] == 'b') {
			(++cnt) %= MOD;
		} else {
			(ans += cnt) %= MOD;
			(cnt += cnt) %= MOD;
		}
	}
	cout << ans << endl;
	return 0;
}