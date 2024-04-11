#include <iostream>
#include <cstring>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)

char s[100100];
int cnt[10]; // B u2 l b a2 s r
	
int main() {
	cin >> s;
	int n = strlen(s);
	forn (i, n) {
		if (s[i] == 'B') {
			++cnt[0];
		}
		if (s[i] == 'u') {
			++cnt[1];
		}
		if (s[i] == 'l') {
			++cnt[2];
		}
		if (s[i] == 'b') {
			++cnt[3];
		}
		if (s[i] == 'a') {
			++cnt[4];
		}
		if (s[i] == 's') {
			++cnt[5];
		}
		if (s[i] == 'r') {
			++cnt[6];
		}
	}
	int ans = 1000000000;
	forn (i, 7) {
		if (i == 1 || i == 4) {
			cnt[i] /= 2;
		}
		ans = min(ans, cnt[i]);
	}
	cout << ans;
	return 0;
}