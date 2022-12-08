#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, k, i, j, tmp, l, r, cnt;
	string s;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		cin >> s;
		cnt = 0;
		l = 0;
		while (s[l] != '*')
			++l;
		r = n - 1;
		while (s[r] != '*')
			--r;
		tmp = j = i = l;
		++cnt;
		s[i] = 'x';
		while (j <= r) {
			while (j - i <= k && j <= r) {
				if (s[j] == '*')
					tmp = j;
				++j;
			}
			i = tmp;
			if (s[tmp] != 'x') {
				s[tmp] = 'x';
				++cnt;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}