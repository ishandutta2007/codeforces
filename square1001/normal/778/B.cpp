#include <map>
#include <string>
#include <vector>
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;
int n, m, tp[5009], a1[5009], a2[5009]; char c[1009]; string s[5009], b1[5009], b2[5009];
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s%*s", c); s[i] = c;
		scanf("%s", c);
		if ('0' <= c[0] && c[0] <= '9') b1[i] = c;
		else {
			b1[i] = c;
			scanf("%s", c);
			if (c[0] == 'A') tp[i] = 1;
			if (c[0] == 'O') tp[i] = 2;
			if (c[0] == 'X') tp[i] = 3;
			scanf("%s", c);
			b2[i] = c;
		}
	}
	for (int i = 0; i < n; i++) {
		if (tp[i] == 0) continue;
		a1[i] = -1, a2[i] = -1;
		for (int j = 0; j < i; j++) {
			if (b1[i] == s[j]) a1[i] = j;
			if (b2[i] == s[j]) a2[i] = j;
		}
	}
	string ret1, ret2;
	for (int i = 0; i < m; i++) {
		int bit = 0;
		vector<int> r(2);
		for (int e = 0; e < 2; e++) {
			vector<int> z(n);
			for (int j = 0; j < n; j++) {
				int g1 = (tp[j] == 0 ? b1[j][i] - 48 : (a1[j] != -1 ? z[a1[j]] : e));
				int g2 = (tp[j] == 0 ? 0 : (a2[j] != -1 ? z[a2[j]] : e));
				if (tp[j] == 0) z[j] = g1;
				if (tp[j] == 1) z[j] = g1 & g2;
				if (tp[j] == 2) z[j] = g1 | g2;
				if (tp[j] == 3) z[j] = g1 ^ g2;
				r[e] += z[j];
			}
		}
		if (r[0] < r[1]) ret1 += '0', ret2 += '1';
		if (r[0] > r[1]) ret1 += '1', ret2 += '0';
		if (r[0] == r[1]) ret1 += '0', ret2 += '0';
	}
	cout << ret1 << endl;
	cout << ret2 << endl;
	return 0;
}