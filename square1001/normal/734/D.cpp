#include <bits/stdc++.h>
using namespace std;
int n, cx, cy; long long x[500009], y[500009]; char s[500009][3];
int main() {
	scanf("%d%d%d", &n, &cx, &cy);
	for(int i = 0; i < n; i++) {
		scanf("%s%lld%lld", s[i], &x[i], &y[i]);
		x[i] -= cx; y[i] -= cy;
	}
	bool flag = false;
	for(int i = 0; i < 8; i++) {
		int p = -1;
		for(int j = 0; j < n; j++) {
			if(x[j] == 0 && y[j] > 0 && (p == -1 || y[j] < y[p])) p = j;
		}
		if(p != -1 && s[p][0] != 'B') flag = true;
		for(int j = 0; j < n; j++) {
			if(s[j][0] == 'R') s[j][0] = 'B';
			else if(s[j][0] == 'B') s[j][0] = 'R';
			long long ex = x[j], ey = y[j];
			x[j] = ex - ey;
			y[j] = ex + ey;
		}
	}
	cout << (flag ? "YES" : "NO") << endl;
	return 0;
}