#include <bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y) {
	int t;
	while (x % y) {
		t = x % y;
		x = y;
		y = t;
	}
	return y;
}

main() {
	int q, i, p, u;
	char s[25], t[25], tmp1[25], tmp2[25];
	long long sc, tc;
	cin >> q;
	while (q--) {
		cin >> s;
		cin >> t;
		for (p = 1; p <= strlen(s) && p <= strlen(t); ++p) {
			strcpy(tmp1, s);
			strcpy(tmp2, t);
			tmp1[p] = tmp2[p] = '\0';
			if (strcmp(tmp1, tmp2) != 0) {
				break;
			}
		}
		p--;
mk:
		sc = tc = 0;
		tmp2[p] = '\0';
		if (p == 0) {
			cout << "-1" << endl;
			continue;
		}
		for (i = 0; i < strlen(s); i += p) {
			strcpy(tmp1, s + i);
			tmp1[p] = '\0';
			if (strcmp(tmp1, tmp2) == 0)
				++sc;
			else {
				sc = 0;
				break;
			}
		}
		for (i = 0; i < strlen(t); i += p) {
			strcpy(tmp1, t + i);
			tmp1[p] = '\0';
			if (strcmp(tmp1, tmp2) == 0)
				++tc;
			else {
				tc = 0;
				break;
			}
		}
		if (sc == 0 || tc == 0) {
			--p;
			goto mk;
		} else {
			int m = sc * tc / gcd(sc, tc);
			for (i = 0; i < m; ++i) {
				cout << tmp2;
			}
			cout << endl;
		}
	}
}